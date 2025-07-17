class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
   int n = startTime.size();
           vector<tuple<int, int, int>> jobs(n);
  for (int i = 0; i < n; ++i)
 jobs[i] = {endTime[i], startTime[i], profit[i]};
  sort(jobs.begin(), jobs.end());
  vector<int> dp(n, 0);
  vector<int> ends(n, 0);
   for (int i = 0; i < n; ++i)
    ends[i] = get<0>(jobs[i]);
 for (int i = 0; i < n; ++i) {
  int curProfit = get<2>(jobs[i]);
  int idx = upper_bound(ends.begin(), ends.begin() + i, get<1>(jobs[i])) - ends.begin() - 1;
if (idx >= 0)
curProfit += dp[idx];
     dp[i] = max(i ? dp[i-1] : 0, curProfit);
 }
 return dp[n-1];
    }
};