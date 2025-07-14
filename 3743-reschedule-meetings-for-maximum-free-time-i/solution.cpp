class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> spaces;
        int prev = 0;
        for(int i = 0; i <= n; i++) {
            int start = i == n ? eventTime : startTime[i];
            spaces.push_back(start - prev);
            if(i < n) prev = endTime[i];
        }
        int ans = 0, now = 0;
        for(int i = 0; i <= n; i++) {
            now += spaces[i];
            ans = max(now, ans);
            if(i >= k) now -= spaces[i - k];
        }
        return ans;
    }
};
