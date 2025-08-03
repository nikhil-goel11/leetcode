class Solution {
public:
    int calculate(string s) {
        int num = 0, res = 0, last = 0;
         char op = '+';
         for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') { res += last; last = num; }
                else if (op == '-') { res += last; last = -num; }
                else if (op == '*') { last *= num; }
                else if (op == '/') { last /= num; }
                op = s[i];
                 num = 0;
            }
         }
         res += last;
         return res;
    }
};