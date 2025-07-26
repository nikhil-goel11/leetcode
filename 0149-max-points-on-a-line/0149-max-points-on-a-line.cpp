class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans =1;
        for(int i=0; i<n; ++i){
            unordered_map<long double, int> slopeCount;
            int same =0, vertical =0, localMax =0;
            for(int j=0; j<n; ++j){
                if(i ==j) continue;
                int dx = points[j][0] -points[i][0];
                int dy = points[j][1] -points[i][1];
                if(dx == 0 && dy ==0){
                    same++;
                } else if(dx == 0){
                    vertical++;
                }else{
                    long double slope = (long double) dy/dx;
                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
                localMax= max(localMax, vertical);
            }
            ans = max(ans, localMax + same+1);
        }
        return ans;
    }
};