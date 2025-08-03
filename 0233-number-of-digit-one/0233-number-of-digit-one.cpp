class Solution {
public:
    int countDigitOne(int n) {
        long res = 0, factor = 1;
         while (n / factor) {
            long lower = n % factor;
            long curr = (n / factor) % 10;
            long higher = n / (factor * 10);
            if (curr == 0) res += higher * factor;
             else if (curr == 1) res += higher * factor + lower + 1;
             else res += (higher + 1) * factor;
             factor *= 10;
         }
         return res;
    }
};