class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
         while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            }else{
                stack.push_back(token);
            }
         }
         string res = "/";
          for (int i = 0; i < stack.size(); ++i) {
            res += stack[i];
            if (i != stack.size() - 1) res += "/";
          }
          return res;
    }
};