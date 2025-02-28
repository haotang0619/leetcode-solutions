class Solution {
public:
    bool isOverlap(vector<int>& int1, vector<int>& int2) {
        if(int1[1] < int2[0] || int1[0] > int2[1]) return false;
        return true;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        vector<vector<int>> ans;
        bool flag = false;
        int left = INT_MAX, right = INT_MIN;
        int n = intervals.size();
        if(newInterval[1] < intervals[0][0]) ans.push_back(newInterval);

        for(int i = 0; i < n; i++) {
            if(i > 0 && newInterval[0] > intervals[i - 1][1] && newInterval[1] < intervals[i][0]) ans.push_back(newInterval);

            if(isOverlap(intervals[i], newInterval)) {
                flag = true;
                left = min(left, min(intervals[i][0], newInterval[0]));
                right = max(right, max(intervals[i][1], newInterval[1]));
            } else {
                if(flag) {
                    ans.push_back({left, right});
                    flag = false;
                }
                ans.push_back(intervals[i]);
            }
        }
        if(flag) ans.push_back({left, right});
        if(newInterval[0] > intervals[n - 1][1]) ans.push_back(newInterval);
        return ans;
    }
};
