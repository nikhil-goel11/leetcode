class Solution {
vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i,int j,const int& n,const int& m,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1;
        for(auto [dx,dy] : dir){
            int x=i+dx,y=j+dy;
            if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[i][j]){
                res=max(res,1+dfs(x,y,n,m,matrix,dp));
            }
        }
        return dp[i][j]=res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),res=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,dfs(i,j,n,m,matrix,dp));
            }
        }
        return res;
        
    }
};