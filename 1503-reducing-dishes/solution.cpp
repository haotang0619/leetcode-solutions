class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0, n = satisfaction.size();
        for(int i = 0; i < n; i++) {
            int now = 0;
            for(int j = i; j < n; j++) {
                now += satisfaction[j] * (j - i + 1);
            }
            ans = max(ans, now);
        }
        return ans;
    }
};
