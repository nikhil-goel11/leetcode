class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
       for (int a = 1; a < n; ++a) {
        int b = n - a;
        auto hasZero = [](int x) {
            while (x) {
                if (x % 10 == 0) return true;
                x /= 10;
            }
            return false;
        };
        if (!hasZero(a) && !hasZero(b)) return {a, b};
    }
    return {};  
    }
};