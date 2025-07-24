class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                 for (auto& d : dirs) {
                     int ni = i + d[0], nj = j + d[1];
                     if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                      live += board[ni][nj] & 1; 
                 }
                 if ((board[i][j] & 1) && (live == 2 || live == 3))
                 board[i][j] |= 2;
                  if (!(board[i][j] & 1) && live == 3)
                   board[i][j] |= 2; 

            }
        }
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
         board[i][j] >>= 1;
    }
};