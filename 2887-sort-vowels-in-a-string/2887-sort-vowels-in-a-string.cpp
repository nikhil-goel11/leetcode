class Solution {
public:
    string sortVowels(string s) {
        vector<int> idx;
    vector<char> vowels;
    auto isVowel = [](char c) {
        string v = "aeiouAEIOU";
        return v.find(c) != string::npos;
    };
    for (int i = 0; i < s.size(); ++i)
        if (isVowel(s[i])) {
            idx.push_back(i);
            vowels.push_back(s[i]);
        }
    sort(vowels.begin(), vowels.end());
    for (int i = 0; i < idx.size(); ++i)
        s[idx[i]] = vowels[i];
    return s;
    }
};