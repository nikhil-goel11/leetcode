class Solution {
    public:
        vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<long long> powers;
        for (int i = 0; i < 31; i++) {
         if (n & (1 << i)) powers.push_back(1LL << i);
        }
       vector<long long> prefix(powers.size() + 1, 1);
       for (int i = 0; i < powers.size(); i++) {
prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
}
vector<int> ans;
 for (auto &q : queries) {
    int l = q[0], r = q[1];
    long long prod = (prefix[r + 1] * powmod(prefix[l], MOD - 2, MOD)) % MOD;
            ans.push_back((int)prod);
 }
 return ans;
        }
        long long powmod(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
         if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
         exp >>= 1;
         }
         return res;
        }
};