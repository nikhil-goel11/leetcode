class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;
        unordered_map<string, vector<string>> parents;
        unordered_set<string> level, next_level;
        level.insert(beginWord);

        bool found = false;
        while (!level.empty() && !found) {
            for (const string& w : level) dict.erase(w);
            for (const string& w : level) {
                string cur = w;
                for (int i = 0; i < cur.size(); ++i) {
                    char orig = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == orig) continue;
                        cur[i] = c;
                        if (dict.count(cur)) {
                            next_level.insert(cur);
                            parents[cur].push_back(w);
                            if (cur == endWord) found = true;
                        }
                    }
                    cur[i] = orig;
                }
            }
            swap(level, next_level);
            next_level.clear();
        }
        if (!found) return res;
        vector<string> path = {endWord};
        function<void(const string&)> dfs = [&](const string& w) {
            if (w == beginWord) {
                vector<string> p = path;
                reverse(p.begin(), p.end());
                res.push_back(p);
                return;
            }
            for (const string& par : parents[w]) {
                path.push_back(par);
                dfs(par);
                path.pop_back();
            }
        };
        dfs(endWord);
        return res;
    }
};