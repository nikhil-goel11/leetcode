class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
                vector<int> dp(n + 1, 0), prev(n + 1, 0);
                        for (int i = 1; i <= m; ++i) {
                                    for (int j = 1; j <= n; ++j) {
if (matrix[i - 1][j - 1] == 1)
   dp[j] = 1 + min({dp[j - 1], prev[j], prev[j - 1]});
                                                                                        else
                                                                                                            dp[j] = 0;
                                                                                                                            ans += dp[j];
                                                                                                                                        }
swap(dp, prev);
                                                                                                                                                                fill(dp.begin(), dp.end(), 0);
                                                                                                                                                                        }
                                                                                                                                                                                return ans;
    }
};