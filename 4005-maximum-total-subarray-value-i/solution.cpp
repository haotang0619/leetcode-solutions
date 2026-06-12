class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxNum = INT_MIN, minNum = INT_MAX;
        for(auto n : nums) {
            maxNum = max((long long)n, maxNum);
            minNum = min((long long)n, minNum);
        }
        return (maxNum - minNum) * k;
    }
};
