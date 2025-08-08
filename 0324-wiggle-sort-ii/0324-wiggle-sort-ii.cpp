class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int n = nums.size();
        int mid = (n + 1) / 2, end = n;
         for (int i = 0, j = mid - 1, k = n - 1; i < n; ++i)
         nums[i] = (i % 2 == 0) ? arr[j--] : arr[k--];
    }
};