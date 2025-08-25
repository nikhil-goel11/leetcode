class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(); 
        if(m==0) return {};
        int n = mat[0].size();
        vector<int> ans; ans.reserve(m*n);
        int r = 0, c = 0; 
        bool up = true;
        while(ans.size() < m*n){
            ans.push_back(mat[r][c]);
            if(up){
                if(c == n-1){ r++; up = false; }
                else if(r == 0){ c++; up = false; }
                else { r--; c++; }
            }else{
                if(r == m-1){ c++; up = true; }
                else if(c == 0){ r++; up = true; }
                else { r++; c--; }
            }
        }
        return ans;
    }
};