class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
         string word;
         while (iss >> word) words.push_back(word);
         reverse(words.begin(), words.end());
         return join(words, " ");  
    }

    string join(const vector<string>& v, const string& delim) {
        string res;
        for(int i=0; i<v.size(); ++i){
            if(i) res += delim;
            res += v[i];
        }
        return res;
    }
};