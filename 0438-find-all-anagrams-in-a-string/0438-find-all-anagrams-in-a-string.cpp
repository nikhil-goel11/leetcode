class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()< p.size()) return res;
        vector<int> phash(26,0), shash(26,0);
        for(char c: p) phash[c -'a']++;
        for(int i =0; i<s.size(); ++i){
            shash[s[i] - 'a']++;
            if(i>= p.size()) shash[s[i - p.size()] -'a']--;
            if(shash == phash) res.push_back(i-p.size() +1);
        }
        return res;
    }
};