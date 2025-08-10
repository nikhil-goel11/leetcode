class Solution {
    public:
        int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, uniqueDigits = 9, available = 9;
        for (int i = 2; i <= n && available > 0; ++i) {
        uniqueDigits *= available;
        res += uniqueDigits;
         available--;
         }                                                                              return res;
    }
    };

