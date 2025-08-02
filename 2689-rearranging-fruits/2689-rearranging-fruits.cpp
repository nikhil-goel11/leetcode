class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       unordered_map<int, int> freq;
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> needA, needB;
        for (auto& [num, cnt] : freq) {
            if (cnt % 2 != 0) return -1;
            if (cnt > 0) needA.insert(needA.end(), cnt/2, num);
            if (cnt < 0) needB.insert(needB.end(), -cnt/2, num);
        }
        if (needA.empty()) return 0;
        sort(needA.begin(), needA.end());
        sort(needB.rbegin(), needB.rend());

        int mn = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
        long long res = 0;
        for (size_t i = 0; i < needA.size(); ++i) {
            res += min(2LL*mn, 1LL * min(needA[i], needB[i]));

        }
        return res;
    }
};