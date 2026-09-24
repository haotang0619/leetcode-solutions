class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        auto getEdge = [&](vector<int>& V1, vector<int>& V2) {
            double x1 = V1[0], y1 = V1[1], x2 = V2[0], y2 = V2[1];
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        };
        auto getArea = [&](vector<vector<int>> v) {
            auto &A = v[0], &B = v[1], &C = v[2];
            double a = getEdge(A, B), b = getEdge(B, C), c = getEdge(A, C);
            double mx = max({a, b, c}), left = a + b + c - mx;
            if(left <= mx) return 0.0;
            double s = (a + b + c) / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        };
        double ans = 0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    ans = max(ans, getArea({points[i], points[j], points[k]}));
                }
            }
        }
        return ans;
    }
};
