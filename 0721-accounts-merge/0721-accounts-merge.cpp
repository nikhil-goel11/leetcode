class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent; 
                unordered_map<string, string> emailToName;
                function<string(string)> find = [&](string x) {
                 return parent[x] == x ? x : parent[x] = find(parent[x]);
               };
                    for (auto& acc : accounts) {
                        string name = acc[0];
                         for (int i = 1; i < acc.size(); ++i) {
                            parent[acc[i]] = acc[i];
                            emailToName[acc[i]] = name;
                         }

                         }
                          for (auto& acc : accounts) {
                            string root = find(acc[1]);
                             for (int i = 2; i < acc.size(); ++i)
                             parent[find(acc[i])] = root;
                          }
                           unordered_map<string, set<string>> unions;
                            for (auto& acc : accounts)
                            for (int i = 1; i < acc.size(); ++i)
                            unions[find(acc[i])].insert(acc[i]);

                            vector<vector<string>> res;
                            for (auto& [root, emails] : unions) {
                                 vector<string> merged{emailToName[root]};
                    merged.insert(merged.end(), emails.begin(), emails.end());
                     res.push_back(merged);
                            }
                            return res;

                }    
};