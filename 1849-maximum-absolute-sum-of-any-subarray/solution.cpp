class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> prefix_sum;
        int sum = 0;
        int maxNum = INT_MIN, minNum = INT_MAX;
        for(auto x : nums) {
            sum += x;
            prefix_sum.push_back(sum);
            maxNum = max(maxNum, sum);
            minNum = min(minNum, sum);
        }
        return max(maxNum > 0 ? abs(maxNum + min(minNum, 0)) : 0, minNum < 0 ? abs(minNum - max(maxNum, 0)) : 0);
    }
};
