class Solution {
public:
    char kthCharacter(int k) {
        int level =0, len =1;
        while(len<k){
            level++;
            len *= 2;
        }
        int pos =k-1;
        char c= 'a';
        while(level>0){
            int half =1<< (level -1);
            if(pos >= half){
                pos -= half;
                c = (c-'a'+1)%26 +'a';
            }
            level--;
        }
        return c;
    }
};