class Solution {
public:
    int characterReplacement(string s, int k) {
     vector<int> count(26,0);
     int maxCount =0, left =0, res =0;
     for(int right =0; right< s.size(); ++right){
        maxCount = max(maxCount, ++count[s[right]-'A']);
        while((right -left +1)-maxCount > k){
            --count[s[left]-'A'];
            ++left;
        }
        res =max(res,right-left+1);
     }   
     return res;
    }
};