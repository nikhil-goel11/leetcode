class Solution {
    double r, xc, yc;
public:
    Solution(double radius, double x_center, double y_center) : r(radius), xc(x_center), yc(y_center)
     { srand(time(nullptr)); }
    
    vector<double> randPoint() {
         double u = (double)rand() / RAND_MAX;
         double v = (double)rand() / RAND_MAX;
         double theta = 2.0 * M_PI * u;
         double rad = sqrt(v) * r;
         double x = xc + rad * cos(theta);
         double y = yc + rad * sin(theta);
         return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */