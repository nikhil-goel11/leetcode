class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
    int res = 0;
    istringstream ss(text);
    string word;
    while (ss >> word) {
        bool ok = true;
        for (char c : word)
            if (broken.count(c)) { ok = false; break; }
        res += ok;
    }
    return res;
    }
};