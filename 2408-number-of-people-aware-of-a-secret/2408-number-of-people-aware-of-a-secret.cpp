class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
    vector<long long> dp(n + 2);
    dp[1] = 1;
    for (int day = 1; day <= n; ++day) {
        for (int share = day + delay; share < day + forget && share <= n; ++share) {
            dp[share] = (dp[share] + dp[day]) % MOD;
        }
    }
    long long ans = 0;
    for (int day = n - forget + 1; day <= n; ++day) {
        ans = (ans + dp[day]) % MOD;
    }
    return ans;
    }
};