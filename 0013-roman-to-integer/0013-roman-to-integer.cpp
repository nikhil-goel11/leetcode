class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int cur = val[s[i]];
             int next = i + 1 < n ? val[s[i + 1]] : 0;
             if (cur < next) ans -= cur;
             else ans += cur;
        }
        return ans;
    }
};