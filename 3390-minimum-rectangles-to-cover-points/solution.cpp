class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int ans = 0, now = -1;
        for(auto& p : points) {
            if(p[0] > now) ans++, now = p[0] + w;
        }
        return ans;
    }
};
