class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            pre[i+1] = pre[i] + fruits[i][1];
        }
        int res = 0;
        for (int x = 0; x <= k; ++x) {
            int l = startPos - x, r = startPos + max(0, k - 2 * x);
            int li = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int ri = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            res = max(res, pre[ri] - pre[li]);
        }
        for (int x = 0; x <= k; ++x) {
            int r = startPos + x, l = startPos - max(0, k - 2 * x);
             int li = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
             int ri = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
             res = max(res, pre[ri] - pre[li]);
        }
        return res;
    }
};