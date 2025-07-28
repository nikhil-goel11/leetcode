class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
                unordered_set<string> dict(wordDict.begin(), wordDict.end());
                        unordered_map<string, vector<string>> memo;
                                return helper(s, dict, memo);
                                    }
                                        
                                            vector<string> helper(string s, unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
                                                    if (memo.find(s) != memo.end()) return memo[s];
                                                            vector<string> res;
                                                                    if (s.empty()) {
                                                                                res.push_back("");
                                                                                            return res;
                                                                                                    }
                                                                                                            for (int i = 1; i <= s.size(); ++i) {
                                                                                                                        string word = s.substr(0, i);
                                                                                                                                    if (dict.count(word)) {
                                                                                                                                                    vector<string> rest = helper(s.substr(i), dict, memo);
                                                                                                                                                                    for (string r : rest) {
                                                                                                                                                                                        res.push_back(word + (r.empty() ? "" : " " + r));
                                                                                                                                                                                                        }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                    memo[s] = res;
                                                                                                                                                                                                                                            return res;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                };

