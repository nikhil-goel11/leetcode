struct TrieNode{
    TrieNode* children[26]={};
    bool isEnd = false;
};

class WordDictionary {
    TrieNode* root;
    bool dfs(string& word, int idx, TrieNode* node){
        if(idx == word.size()) return node-> isEnd;
        if(word[idx] == '.'){
            for(int i=0; i<26; ++i)
            if(node-> children[i] && dfs(word, idx+1,node->children[i]))
            return true;
            return false;
        }
        else{
            int c=word[idx] -'a';
            if(!node->children[c]) return false;
            return dfs(word, idx+1, node->children[c]);
        }
    }
public:
    WordDictionary() { root= new TrieNode();
        
    }
    
    void addWord(string word) {
        TrieNode* node =root;
        for(char ch:word){
            int c = ch-'a';
            if(!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */