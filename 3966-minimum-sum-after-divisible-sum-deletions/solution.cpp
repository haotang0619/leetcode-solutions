class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        vector<long long> minSum(k, 1e12);
        minSum[0] = 0;
        long long prev = 0;
        long long sum = 0;
        for(auto x : nums) {
            sum += x;
            int rem = sum % k;
            minSum[rem] = min(minSum[rem], prev + x);
            prev = minSum[rem];
        }
        return minSum[sum % k];
    }
};
