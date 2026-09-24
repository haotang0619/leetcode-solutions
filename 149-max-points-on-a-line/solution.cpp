class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1, div = gcd(dx, dy);
                dx /= div, dy /= div;
                if(dx == 0) dy = 1;
                else if(dx < 0) dx *= -1, dy *= -1;
                
                int cnt = 2;
                for(int k = j + 1; k < n; k++) {
                    int x3 = points[k][0], y3 = points[k][1];
                    int dx1 = x3 - x1, dy1 = y3 - y1, div1 = gcd(dx1, dy1);
                    dx1 /= div1, dy1 /= div1;
                    if(dx1 == 0) dy1 = 1;
                    else if(dx1 < 0) dx1 *= -1, dy1 *= -1;
                    if(dx == dx1 && dy == dy1) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
