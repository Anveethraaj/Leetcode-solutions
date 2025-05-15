class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxi = -1;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    double x1 = points[i][0];
                    double x2 = points[j][0];
                    double x3 = points[k][0];

                    double y1 = points[i][1];
                    double y2 = points[j][1];
                    double y3 = points[k][1];

                    double ans = 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) +
                                        x3 * (y1 - y2));

                    if (maxi < abs(ans)) {
                        maxi = abs(ans);
                    }
                }
            }
        }
        return maxi;
    }
};