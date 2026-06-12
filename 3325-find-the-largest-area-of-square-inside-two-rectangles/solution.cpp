class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int x1 = bottomLeft[i][0], y1 = bottomLeft[i][1];
                int x2 = topRight[i][0], y2 = topRight[i][1];
                int x3 = bottomLeft[j][0], y3 = bottomLeft[j][1];
                int x4 = topRight[j][0], y4 = topRight[j][1];
                
                int xDiff = 0, yDiff = 0;
                if(x1 >= x3 && x1 <= x4) xDiff = min(x2, x4) - x1;
                if(x3 >= x1 && x3 <= x2) xDiff = min(x2, x4) - x3;
                if(y1 >= y3 && y1 <= y4) yDiff = min(y2, y4) - y1;
                if(y3 >= y1 && y3 <= y2) yDiff = min(y2, y4) - y3;
                long long l = min(xDiff, yDiff);
                ans = max(ans, l * l);
            }
        }
        return ans;
    }
};
