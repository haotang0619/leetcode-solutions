class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int INF = 1e6, ans = INF, n = arr.size(), sum = 0;
        vector<int> dp(n, INF); // min len by far
        for(int l = 0, r = 0; r < n; r++) {
            if(r > 0) dp[r] = dp[r - 1];
            sum += arr[r];
            while(sum > target) sum -= arr[l++];
            if(sum == target) {
                int len = r - l + 1;
                dp[r] = min(dp[r], len);
                if(l > 0) ans = min(ans, len + dp[l - 1]);
            }
        }
        return ans == INF ? -1 : ans;
    }
};
