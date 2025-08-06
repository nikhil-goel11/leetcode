class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
       prefix.push_back(0);
        for (int n : nums) prefix.push_back(prefix.back() + n);
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */