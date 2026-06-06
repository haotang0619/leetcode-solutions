class Solution {
public:
    // Figured out by myself
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int minLandEnd = INT_MAX, minWaterEnd = INT_MAX, ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < m; i++) {
            minWaterEnd = min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
        }
        for(int i = 0; i < n; i++) {
            ans = min(ans, max(minWaterEnd, landStartTime[i]) + landDuration[i]);
        }
        for(int i = 0; i < m; i++) {
            ans = min(ans, max(minLandEnd, waterStartTime[i]) + waterDuration[i]);
        }
        return ans;
    }
};
