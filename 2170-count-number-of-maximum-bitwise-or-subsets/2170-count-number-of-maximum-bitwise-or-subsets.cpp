class Solution {
public:
int max_or =0, count =0;
void dfs(vector<int>& nums, int idx, int curr_or){
    if(idx == nums.size()){
        if(curr_or == max_or) count++;
        return;
    }
    dfs(nums,idx+1, curr_or | nums[idx]);
    dfs(nums,idx+1,curr_or);
}
    int countMaxOrSubsets(vector<int>& nums) {
        for(int n: nums) max_or |= n;
        dfs(nums,0,0);
        return count;
    }
};