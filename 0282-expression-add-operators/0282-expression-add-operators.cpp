class Solution {
    public:
        vector<string> res;
            void dfs(string& num, int target, int pos, long long eval, long long prev, string path) {
                    if (pos == num.size()) {
                                if (eval == target) res.push_back(path);
                                            return;
                                                    }
  for (int i = pos; i < num.size(); ++i) {
   if (i != pos && num[pos] == '0') break; 
                                                                                    string curStr = num.substr(pos, i - pos + 1);
                                                                                                long long cur = stoll(curStr);
                                                                                                            if (pos == 0) {
  dfs(num, target, i+1, cur, cur, curStr);
    } else {
  dfs(num, target, i+1, eval + cur, cur, path + "+" + curStr);
                                                                                                                                                                        dfs(num, target, i+1, eval - cur, -cur, path + "-" + curStr);
  dfs(num, target, i+1, eval - prev + prev * cur, prev * cur, path + "*" + curStr);
 }
 }
}
  vector<string> addOperators(string num, int target) {
 res.clear();
   dfs(num, target, 0, 0, 0, "");
                                                                                                                                                                                                                                            return res;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                };
