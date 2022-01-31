class Solution {
    double radius, x_center, y_center;
    double PI = 3.14159265358979323846264;
  public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        vector<double> randPoint(2);
        
        double r = sqrt((double)rand()/RAND_MAX) * radius;
        double theta = 2 * PI * ((double)rand() / RAND_MAX);
        
        randPoint[0] = x_center + r * cos(theta);
        randPoint[1] = y_center + r * sin(theta);
        
        return randPoint;
    }
};
