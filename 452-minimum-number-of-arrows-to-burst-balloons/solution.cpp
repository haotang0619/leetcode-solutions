class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(), points.end());
        int ans = 1;
        vector<int> curr = points[0];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] <= curr[1]) {
                curr = {max(points[i][0], curr[0]), min(points[i][1], curr[1])};
            } else {
                ans++;
                curr = points[i];
            }
        }
        return ans;
    }
};
