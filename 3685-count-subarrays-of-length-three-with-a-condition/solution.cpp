class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = i + 2;
            if((nums[i] + nums[k]) * 2 == nums[j]) ans++;
        }
        return ans;
    }
};
