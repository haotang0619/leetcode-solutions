class Solution {
public:
    long long MAX_SUM = 1e14;
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pSum(n), pProd(n);
        pSum[0] = 0;
        for(int i = 1; i < n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        pProd[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(pProd[i + 1] == LLONG_MAX) pProd[i] = LLONG_MAX;
            else {
                if(nums[i + 1] > MAX_SUM / pProd[i + 1]) {
                    pProd[i] = LLONG_MAX;
                } else {
                    pProd[i] = pProd[i + 1] * nums[i + 1];
                    if(pProd[i] > MAX_SUM) pProd[i] = LLONG_MAX;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(pSum[i] == pProd[i]) return i;
        }
        return -1;
    }
};
