class Trie {
    struct TrieNode{
        TrieNode* children[26] ={};
        bool isWord = false;
    };
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word){
            int idx = c-'a';
            if(!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c : word){
            int idx = c-'a';
            if(!node-> children[idx]) return false;
            node = node->children[idx];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c: prefix){
            int idx = c-'a';
            if(!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */