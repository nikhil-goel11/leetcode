class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;

        bool hasVowel =false, hasConsonant = false;
        string vowels = "aeiouAEIOU";
        for(char c : word){
            if(!isdigit(c) && !isalpha(c)) return false;
            if(isalpha(c)){
                if(vowels.find(c) != string :: npos) hasVowel = true;
                else hasConsonant = true;
            }
        }
        return hasVowel && hasConsonant;
    }
};