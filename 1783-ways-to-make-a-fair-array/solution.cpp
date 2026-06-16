class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> evenSum(1, 0), oddSum(1, 0);
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) evenSum.push_back(evenSum[i / 2] + nums[i]);
            else oddSum.push_back(oddSum[i / 2] + nums[i]);
        }
        int ans = 0, n1 = evenSum.size(), n2 = oddSum.size();
        for(int i = 0; i < nums.size(); i++) {
            int eSum, oSum;
            if(i % 2 == 0) {
                eSum = evenSum[i / 2] + oddSum[n2 - 1] - oddSum[i / 2];
                oSum = oddSum[i / 2] + evenSum[n1 - 1] - evenSum[i / 2 + 1];
            } else {
                eSum = evenSum[i / 2 + 1] + oddSum[n2 - 1] - oddSum[i / 2 + 1];
                oSum = oddSum[i / 2] + evenSum[n1 - 1] - evenSum[i / 2 + 1];
            }
            if(eSum == oSum) ans++;
        }
        return ans;
    }
};
