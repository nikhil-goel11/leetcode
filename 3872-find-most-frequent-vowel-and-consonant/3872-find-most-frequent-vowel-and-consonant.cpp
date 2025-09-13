class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    string vowels = "aeiou";
    int maxV = 0, maxC = 0;
    for (int i = 0; i < 26; ++i) {
        char ch = 'a' + i;
        if (vowels.find(ch) != string::npos)
            maxV = max(maxV, freq[i]);
        else
            maxC = max(maxC, freq[i]);
    }
    return maxV + maxC;
    }
};