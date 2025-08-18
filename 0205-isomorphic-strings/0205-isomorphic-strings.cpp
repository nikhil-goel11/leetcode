class Solution {
public:
    bool isIsomorphic(string s, string t) {
         if (s.size() != t.size()) return false;
         int m1[256] = {0}, m2[256] = {0};
          for (int i = 0; i < s.size(); ++i) {
             unsigned char a = s[i];    
             unsigned char b = t[i];
             if ((m1[a] && m1[a] != b) || (m2[b] && m2[b] != a)) return false;
             m1[a] = b;
             m2[b] = a;
          }
          return true; 
    }
};