class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), res=0;
        for(int i=1; i<n-1; ++i){
            if (nums[i] == nums[i-1]) continue;
            int l=i-1,r=i+1;
            while(l>=0 && nums[l] ==nums[i]) --l;
            while(r<n && nums[r] == nums[i]) ++r;
            if(l >= 0 && r<n){
                if (nums[i] > nums[l] && nums[i] > nums[r]) res++;
                if (nums[i] < nums[l] && nums[i] < nums[r]) res++;
            }
        }
        return res;
    }
};