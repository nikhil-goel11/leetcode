class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getRC = [&](int s){
            int quot = (s-1)/n, rem = (s-1)%n;
            int r =n-1-quot;
            int c = (quot % 2==0)? rem : n-1-rem;
            return make_pair(r,c);
        };
        vector<bool> visited(n * n + 1, false);
         queue<pair<int, int>> q;
         q.push({1, 0});
         visited[1] = true;
         while (!q.empty()) {
            auto[s, moves] = q.front(); q.pop();
            if(s == n*n) return moves;
            for(int i =1; i<= 6 && s+i <= n*n; ++i){
                int ns = s+i;
                auto[r,c] = getRC(ns);
                if(board[r][c] != -1) ns= board[r][c];
                if(!visited[ns]){
                    visited[ns] = true;
                    q.push({ns, moves+1});
                }
            }
         } 
         return -1;
    }
};