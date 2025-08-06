class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<long> ugly(n, 1);
        int k = primes.size();
        vector<int> idx(k, 0);
        vector<long> next(primes.begin(), primes.end());
        for (int i = 1; i < n; ++i) {
            long mn = *min_element(next.begin(), next.end());
            ugly[i] = mn;
            for (int j = 0; j < k; ++j) {
                if (next[j] == mn) {
                    idx[j]++;
                    next[j] = ugly[idx[j]] * primes[j];
                }
            }
        }
        return (int)ugly[n-1];
    }
};