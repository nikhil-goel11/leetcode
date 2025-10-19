class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        queue<string> q;
        string ans = s;
        q.push(s);
        seen.insert(s);
        while (!q.empty()) {
        string cur = q.front();
         q.pop();
       ans = min(ans, cur);
        string t = cur;
         for (int i = 1; i < t.size(); i += 2)
           t[i] = (t[i] - '0' + a) % 10 + '0';
              if (!seen.count(t)) {
          seen.insert(t);
            q.push(t);
     }
            rotate(cur.begin(), cur.begin() + (cur.size() - b), cur.end());
             if (!seen.count(cur)) {
            seen.insert(cur);
             q.push(cur);
   }
}
          return ans;
    }
};