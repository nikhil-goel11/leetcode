class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
         sort(strs.begin(), strs.end());
         const string& a = strs.front();
         const string& b = strs.back();
         string pref;
        for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
         if (a[i] != b[i]) break;
             pref.push_back(a[i]);
            }
             return pref;            
    }
};