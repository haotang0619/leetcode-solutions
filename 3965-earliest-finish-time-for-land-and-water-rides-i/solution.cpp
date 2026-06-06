class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int l1 = landStartTime[i] + landDuration[i];
                int w1 = max(l1, waterStartTime[j]) + waterDuration[j];
                int w2 = waterStartTime[j] + waterDuration[j];
                int l2 = max(w2, landStartTime[i]) + landDuration[i];
                ans = min(ans, min(w1, l2));
            }
        }
        return ans;
    }
};
