class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, minutes = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
         for(int j = 0; j < n; ++j)
          if(grid[i][j] == 2) q.push({i, j});
          else if(grid[i][j] == 1) ++fresh;
          int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
          while(!q.empty() && fresh) {
            int sz = q.size();
            while(sz--) {
                auto [x, y] = q.front(); q.pop();
                for(auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    --fresh;
                    }
                }
            }
            ++minutes;
          }
          return fresh ? -1 : minutes;
    }
};