class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        priority_queue<int> leftMax;
        priority_queue<int, vector<int>, greater<int>> rightMin;
        vector<long long> leftSum(2 *n+1,0), rightSum(2* n+1,0);
        long long sum =0;
        for(int i=0; i<2*n;++i){
            sum += nums[i];
            leftMax.push(nums[i]);
            if(leftMax.size() >n){
                sum -= leftMax.top();
                leftMax.pop();
            }
            leftSum[i+1] = sum;
        }
        sum =0;
        for(int i=3*n-1; i>= n; --i){
            sum += nums[i];
            rightMin.push(nums[i]);
            if(rightMin.size()>n){
                sum -= rightMin.top();
                rightMin.pop();
            }
            rightSum[i-n]=sum;
        }
        long long res = LLONG_MAX;
        for(int i=n; i<=2*n; ++i)
        res = min(res, leftSum[i] - rightSum[i-n]);
        return res;
    }
};