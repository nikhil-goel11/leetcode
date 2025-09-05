class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; ++k) {
        long long rem = (long long)num1 - (long long)num2 * k;
        if (rem < k) continue;
        int bits = __builtin_popcountll(rem);
        if (bits <= k && k <= rem) return k;
    }
    return -1;
    }
};