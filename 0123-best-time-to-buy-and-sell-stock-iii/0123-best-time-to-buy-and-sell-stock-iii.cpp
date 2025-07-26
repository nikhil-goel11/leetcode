class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> left(n,0), right(n+1,0);
        int minP = prices[0];
        for(int i=1; i<n; ++i){
            minP = min(minP, prices[i]);
            left[i] = max(left[i-1], prices[i]-minP);
        }
        int maxP = prices[n-1];
        for(int i=n-2; i>= 0; --i){
            maxP = max(maxP, prices[i]);
            right[i] = max(right[i+1], maxP-prices[i]);
        }
        int res =0;
        for(int i=0; i<n; ++i)
        res = max(res, left[i] + right[i+1]);
        return res;
    }
};