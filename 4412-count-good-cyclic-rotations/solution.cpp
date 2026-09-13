class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long pSum = 0, sSum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i < n / 2) pSum += nums[i];
            else sSum += nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(pSum > sSum) ans++;
            pSum -= nums[i], pSum += nums[(n / 2 + i) % n];
            sSum += nums[i], sSum -= nums[(n / 2 + i) % n];
        }
        return ans;
    }
};
