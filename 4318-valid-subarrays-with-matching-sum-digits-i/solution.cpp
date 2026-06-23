class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0, n = nums.size();
        vector<long long> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                long long sum = pSum[i] - pSum[j];
                int l = floor(log10(sum));
                long long div = pow(10, l);
                if(sum % 10 == x && sum / div == x) ans++;
            }
        }
        return ans;
    }
};
