class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> copied(n);
        for(int i = 0; i < n; i++) copied[i] = {intervals[i][0], i};
        sort(copied.begin(), copied.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int idx = lower_bound(copied.begin(), copied.end(), vector<int>({intervals[i][1], 0})) - copied.begin();
            ans[i] = idx >= n ? -1 : copied[idx][1];
        }
        return ans;
    }
};
