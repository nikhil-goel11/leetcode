class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        int ans = -1;
        for (auto &p : cnt) if (p.first == p.second) ans = max(ans, p.first);
        return ans;
    }
};