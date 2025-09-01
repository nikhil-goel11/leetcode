class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     unordered_map<string, int> seen;
    vector<string> res;
    for (int i = 0; i + 9 < s.size(); ++i) {
        string sub = s.substr(i, 10);
        if (++seen[sub] == 2) res.push_back(sub); 
    }
    return res;
    }
};