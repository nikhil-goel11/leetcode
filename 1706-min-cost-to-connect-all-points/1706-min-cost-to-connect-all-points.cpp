class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
        vector<int> dist(n, INT_MAX), vis(n, 0);
        auto manh = [&](int i, int j){
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        dist[0] = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int u = -1;
            for(int j = 0; j < n; j++){
                if(!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
            }
            vis[u] = 1;
            ans += dist[u];
            for(int v = 0; v < n; v++){
                if(!vis[v]){
                    int w = manh(u, v);
                    if(w < dist[v]) dist[v] = w;
                }
            }
        }
        return ans;
    
    }
};