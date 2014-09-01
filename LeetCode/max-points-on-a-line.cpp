/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int res = 0;
        if (points.size() <= 2) return points.size();
        
        unordered_map<double, int> slope;
        for (int i = 0; i < points.size(); ++i) {
            // start from point[i]
            slope.clear();
            int sameone = 0;
            int vertical = 0;
            int point_max = 1;
            for (int j = i+1; j < points.size(); ++j) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    sameone += 1;
                } else if (points[j].x == points[i].x) {
                    vertical = vertical == 0 ? 2 : vertical + 1;
                } else {
                    double k = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
                    if (slope.find(k) != slope.end()) slope[k] += 1;
                    else slope[k] = 2;
                    point_max = max(point_max, slope[k]);
                }
            }
            res = max(res, point_max + sameone);
            res = max(res, vertical + sameone);
        }
        return res;
    }
};