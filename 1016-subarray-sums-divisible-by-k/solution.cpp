class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> modCnt(k, 0);
        int ans = 0, sum = 0;
        for(auto num : nums) sum += num, modCnt[((sum % k) + k) % k]++;
        int pSum = 0, target = 0;
        for(auto num : nums) {
            ans += modCnt[target];
            pSum += num;
            target = ((pSum % k) + k) % k;
            modCnt[target]--;
        }
        return ans;
    }
};
