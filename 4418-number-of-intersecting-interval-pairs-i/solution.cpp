class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int mxl = max(intervals[i][0], intervals[j][0]);
                int mnr = min(intervals[i][1], intervals[j][1]);
                if(mxl <= mnr) ans++;
            }
        }
        return ans;
    }
};
