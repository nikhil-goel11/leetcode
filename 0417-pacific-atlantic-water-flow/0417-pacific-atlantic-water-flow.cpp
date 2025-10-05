class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  int m = heights.size(), n = heights[0].size();
  vector<vector<int>> pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0)), res;
  vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
  function<void(int,int,vector<vector<int>>&)> dfs = [&](int i, int j, vector<vector<int>>& ocean) {
   ocean[i][j] = 1;
    for (auto& d : dirs) {
  int ni = i + d.first, nj = j + d.second;
  if (ni < 0 || nj < 0 || ni >= m || nj >= n || ocean[ni][nj]) continue;
   if (heights[ni][nj] < heights[i][j]) continue;
 dfs(ni, nj, ocean);
}
 };
for (int i = 0; i < m; ++i) dfs(i, 0, pac), dfs(i, n-1, atl);
  for (int j = 0; j < n; ++j) dfs(0, j, pac), dfs(m-1, j, atl);
    for (int i = 0; i < m; ++i)
  for (int j = 0; j < n; ++j)
    if (pac[i][j] && atl[i][j]) res.push_back({i, j});
        return res;
    }
};