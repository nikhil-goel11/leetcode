class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto[word, len] = q.front(); q.pop();
            if(word == endWord) return len;
            for(int i=0; i<word.size(); ++i){
                string w = word;
                for(char c ='a'; c<='z'; ++c){
                    w[i] =c;
                    if(wordSet.count(w)){
                        q.push({w, len+1});
                        wordSet.erase(w);
                    }
                }
            }
        }
        return 0;
        
    }
};