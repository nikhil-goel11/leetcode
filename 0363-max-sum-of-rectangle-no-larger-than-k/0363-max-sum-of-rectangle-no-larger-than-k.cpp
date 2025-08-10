class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      int rows = matrix.size(), cols = matrix[0].size();
      int res = INT_MIN;   
      for (int left = 0; left < cols; ++left) {
        vector<int> rowSum(rows, 0);
        for (int right = left; right < cols; ++right) {
        for (int r = 0; r < rows; ++r) {
       rowSum[r] += matrix[r][right];
      }
      set<int> prefixSums;
      prefixSums.insert(0);
      int currSum = 0;
       for (int sum : rowSum) {
        currSum += sum;
        auto it = prefixSums.lower_bound(currSum - k);
        if (it != prefixSums.end()) {
            res = max(res, currSum - *it);
        }
        prefixSums.insert(currSum);
       }
    }
      }
      return res;
    }
};