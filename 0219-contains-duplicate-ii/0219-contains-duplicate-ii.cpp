class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_set<int> win;
         int n = nums.size();
         for (int i = 0; i < n; ++i) {
             if (win.count(nums[i])) return true;
             win.insert(nums[i]);
             if ((int)win.size() > k) win.erase(nums[i - k]);
         }
            return false;
    }
};