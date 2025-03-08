class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double minY = INT_MAX, maxY = INT_MIN;
        double area = 0;
        for(auto &x : squares) {
            minY = min(minY, (double)x[1]);
            maxY = max(maxY, (double)x[1] + (double)x[2]);
            area += (double)x[2] * (double)x[2];
        }
        
        while(true) {
            double mid = (minY + maxY) / 2;
            if(abs(mid - minY) <= 1e-5) return mid;

            double a = 0;
            for(auto &x : squares) {
                a += (double)x[2] * max(min(mid - (double)x[1], (double)x[2]), (double)0);
            }
            if(a < (area / 2)) minY = mid;
            else maxY = mid;
        }
    }
};
