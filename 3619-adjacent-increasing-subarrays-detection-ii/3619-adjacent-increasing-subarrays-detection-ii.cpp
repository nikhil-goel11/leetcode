class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
                vector<int> L(n,1), R(n,1);
     for (int i = 1; i < n; i++) if (nums[i] > nums[i-1]) L[i] = L[i-1] + 1;
 for (int i = n-2; i >= 0; i--) if (nums[i] < nums[i+1]) R[i] = R[i+1] + 1;
    int ans = 0;
    for (int i = 0; i+1 < n; i++) ans = max(ans, min(L[i], R[i+1])); 
     return ans;
    }
};