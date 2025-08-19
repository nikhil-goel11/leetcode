class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0, run =0;
        for(int x: nums){
            if(x == 0) run++;
            else run =0;
            ans += run;
        }
        return ans;
    }
};