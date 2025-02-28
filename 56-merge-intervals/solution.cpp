class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans = {};
        vector<int> curr = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= curr[1]) {
                curr = {curr[0], max(intervals[i][1], curr[1])};
            } else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};
