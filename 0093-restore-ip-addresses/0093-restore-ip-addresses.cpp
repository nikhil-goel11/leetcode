class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
         vector<string> res;
   function<void(int, int, string)> backtrack = [&](int idx, int parts, string curr) {
   if (parts == 4 && idx == s.size()) {
   curr.pop_back(); 
    res.push_back(curr);
     return;
           }
   if (parts == 4 || idx == s.size()) return;
     for (int len = 1; len <= 3 && idx + len <= s.size(); ++len) {
    string seg = s.substr(idx, len);
      if ((seg[0] == '0' && seg.length() > 1) || stoi(seg) > 255) continue;
         backtrack(idx + len, parts + 1, curr + seg + ".");
  }
   };
   backtrack(0, 0, "");
    return res;
    }
};