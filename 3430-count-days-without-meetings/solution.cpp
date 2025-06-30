class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = meetings[0][0] - 1;
        int left = meetings[0][0], right = meetings[0][1];
        for(int i = 1; i < meetings.size(); i++) {
            if(right < meetings[i][0]) {
                ans += meetings[i][0] - right - 1;
                left = meetings[i][0];
            }
            right = max(right, meetings[i][1]);
        }
        return ans + days - right;
    }
};
