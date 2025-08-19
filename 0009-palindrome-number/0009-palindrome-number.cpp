class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        long rev =0, n=x;
        while(n> rev){rev = rev *10 +n %10; n/=10;}
        return n == rev || n == rev/ 10;
    }
};