class Solution {
public:
    double rad ;
    double x1 ;
    double y1 ;
    Solution(double radius, double x_center, double y_center) {
        this->rad = radius;
        this->x1 = x_center;
        this->y1 = y_center;
    }
    vector<double> randPoint() {
        double l = sqrt(double(rand())/RAND_MAX)*rad;
        double deg = 2*M_PI*(double(rand())/RAND_MAX);
        return {x1+l*cos(deg),y1+l*sin(deg)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */