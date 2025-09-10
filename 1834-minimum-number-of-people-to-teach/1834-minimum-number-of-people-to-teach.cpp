class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> needTeach;
    for (auto& f : friendships) {
        int u = f[0] - 1, v = f[1] - 1;
        unordered_set<int> lu(languages[u].begin(), languages[u].end());
        bool ok = false;
        for (int lang : languages[v]) if (lu.count(lang)) ok = true;
        if (!ok) {
            needTeach.insert(u);
            needTeach.insert(v);
        }
    }
    int res = INT_MAX;
    for (int lang = 1; lang <= n; ++lang) {
        int cnt = 0;
        for (int user : needTeach)
            if (find(languages[user].begin(), languages[user].end(), lang) == languages[user].end())
                cnt++;
        res = min(res, cnt);
    }
    return res;
    }
};