class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(points[j][0] - points[i][0] == 0) {
                    int curr = 2;
                    for(int k = j + 1; k < n; k++) {
                        if(points[k][0] == points[j][0]) curr++;
                    }
                    ans = max(ans, curr);
                } else {
                    int dy = points[j][1] - points[i][1];
                    int dx = points[j][0] - points[i][0];
                    int dxB = dx * points[i][1] - dy * points[i][0];
                    int curr = 2;
                    for(int k = j + 1; k < n; k++) {
                        if(dx * points[k][1] == dy * points[k][0] + dxB) curr++;
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};
