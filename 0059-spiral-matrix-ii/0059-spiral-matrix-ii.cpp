class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
         int num = 1, left = 0, right = n - 1, top = 0, bottom = n - 1;
         while (left <= right && top <= bottom) {
            for (int j = left; j <= right; ++j) mat[top][j] = num++;
            ++top;
            for (int i = top; i <= bottom; ++i) mat[i][right] = num++;
            --right;
             if (top <= bottom)
             for (int j = right; j >= left; --j) mat[bottom][j] = num++;
             --bottom;
             if (left <= right)
             for (int i = bottom; i >= top; --i) mat[i][left] = num++;
                         ++left;
         }
         return mat;
    }
};