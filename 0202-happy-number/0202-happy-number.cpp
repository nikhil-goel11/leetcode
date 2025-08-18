class Solution {
public:
    bool isHappy(int n) {
      
        auto nextSum = [](int x){
         int s = 0;
     while (x) { int d = x % 10; s += d * d; x /= 10; }
         return s;
        };
        int slow = n, fast = nextSum(n);
        while (fast != 1 && slow != fast) {
         slow = nextSum(slow);
         fast = nextSum(nextSum(fast));
        }
         return fast == 1;
        }
    
};