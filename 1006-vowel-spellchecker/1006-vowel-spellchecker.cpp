class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
         unordered_set<string> words(wordlist.begin(), wordlist.end());
    unordered_map<string, string> cap, vow;
    auto devowel = [](string s) {
        for (char& c : s)
            if (string("aeiou").find(tolower(c)) != string::npos) c = '*';
            else c = tolower(c);
        return s;
    };
    for (string w : wordlist) {
        string low = w;
        transform(low.begin(), low.end(), low.begin(), ::tolower);
        if (!cap.count(low)) cap[low] = w;
        string v = devowel(w);
        if (!vow.count(v)) vow[v] = w;
    }
    vector<string> res;
    for (string q : queries) {
        if (words.count(q)) res.push_back(q);
        else {
            string low = q;
            transform(low.begin(), low.end(), low.begin(), ::tolower);
            if (cap.count(low)) res.push_back(cap[low]);
            else {
                string v = devowel(q);
                if (vow.count(v)) res.push_back(vow[v]);
                else res.push_back("");
            }
        }
    }
    return res;
    }
};