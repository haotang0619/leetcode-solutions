class Solution {
public:
    int mod = 1e9 + 7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long ans = 0, maxHeadSum = INT_MIN, maxTailSum = INT_MIN, maxSubSum = INT_MIN, sum1 = 0, sum2 = 0, sum3 = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            sum1 += arr[i];
            sum2 += arr[n - 1 - i];
            sum3 += arr[i];
            maxHeadSum = max(maxHeadSum, sum1);
            maxTailSum = max(maxTailSum, sum2);
            maxSubSum = max(maxSubSum, sum3);
            if(sum3 < 0) sum3 = 0;
        }
        if(maxSubSum <= 0) return 0;
        // 1st case: Simply the max subarray sum
        ans = max(ans, maxSubSum);
        // 2nd case: The tail max + (k - 2) * Max(array_sum, 0) + The head max
        if(k >= 2) ans = max(ans, maxTailSum + (k - 2) * max(sum1, 0LL) + maxHeadSum);
        return ans % mod;
    }
};
