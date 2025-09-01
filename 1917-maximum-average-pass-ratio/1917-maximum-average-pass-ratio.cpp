class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](const vector<int>& c) {
        double before = (double)c[0] / c[1];
        double after = (double)(c[0] + 1) / (c[1] + 1);
        return after - before;
    };
    priority_queue<pair<double, pair<int, int>>> pq;
    for (auto& c : classes)
        pq.push({gain(c), {c[0], c[1]}});
    while (extraStudents--) {
        auto [_, pr] = pq.top(); pq.pop();
        int pass = pr.first, total = pr.second;
        pass++, total++;
        pq.push({((double)(pass + 1) / (total + 1)) - ((double)pass / total), {pass, total}});
    }
    double sum = 0;
    while (!pq.empty()) {
        auto [__, pr] = pq.top(); pq.pop();
        sum += (double)pr.first / pr.second;
    }
    return sum / classes.size();
    }
};