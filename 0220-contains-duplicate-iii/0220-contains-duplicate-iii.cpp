class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0) return false;
        map<long, int> window;
        for (int i = 0; i < nums.size(); ++i) {
            long num = (long)nums[i];
            auto it = window.lower_bound(num - valueDiff);
            if (it != window.end() && abs(it->first - num) <= valueDiff)
            return true;
            window[num] = i;
            if (window.size() > indexDiff)
            window.erase(nums[i - indexDiff]);
        }
        return false;
    }
};