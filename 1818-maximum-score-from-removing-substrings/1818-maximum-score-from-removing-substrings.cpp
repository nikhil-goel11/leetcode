class Solution {
public:
int remove(string &s, const string &pat, int score) {
        int n = s.size(), write = 0, res = 0;
            for (int read = 0; read < n; ++read) {
                    s[write++] = s[read];
    if (write >= 2 && s[write-2] == pat[0] && s[write-1] == pat[1]) {
   write -= 2;
   res += score;
        }
      }
    s.resize(write); 
    return res;
   }

    int maximumGain(string s, int x, int y) {
       int res =0;
       if(x>y){
        res += remove(s, "ab", x);
        res += remove(s, "ba",y);
       }
       else{
        res += remove(s, "ba",y);
        res += remove(s, "ab",x);
       }
       return res;
    }
};