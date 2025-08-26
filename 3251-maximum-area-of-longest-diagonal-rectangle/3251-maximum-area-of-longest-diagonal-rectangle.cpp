class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long bestD = -1, bestA = 0;
        for (auto &v : dimensions) {
            long long l = v[0], w = v[1];
            long long d2 = l*l + w*w;
            long long area = l*w;
            if (d2 > bestD || (d2 == bestD && area > bestA)) {
                bestD = d2;
                bestA = area;
            }
        }
        return (int)bestA;
    }
};