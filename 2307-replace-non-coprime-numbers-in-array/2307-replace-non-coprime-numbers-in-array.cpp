class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
       vector<int> stk;
        auto gcd = [](long long a, long long b) {
            while (b) { long long t = b; b = a % b; a = t; }
            return a;
        };
       auto lcm = [&](long long a, long long b) { return a / gcd(a, b) * b; };
        for (int x : nums) {
            long long cur = x;
            while (!stk.empty() && gcd(stk.back(), cur) > 1) {
                cur = lcm(stk.back(), cur);
                stk.pop_back();
            }
            stk.push_back(cur);
        }
        return stk; 
    }
};