class Solution {
    public:
        const int MOD = 1e9 + 7;

            int dfs(int n, int x, int num, vector<vector<int>>& dp) {
                    if (n == 0) return 1;
                            if (n < 0) return 0;
                                    if (pow(num, x) > n) return 0;

                       if (dp[n][num] != -1) return dp[n][num];

                                int power = pow(num, x);
       int take = dfs(n - power, x, num + 1, dp) % MOD;
     int skip = dfs(n, x, num + 1, dp) % MOD;

                                                                            return dp[n][num] = (take + skip) % MOD;
                                                                                }

                                                                                    int numberOfWays(int n, int x) {
                                                                                            vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
                                                                                                    return dfs(n, x, 1, dp);
                                                                                                        }
                                                                                                        };
