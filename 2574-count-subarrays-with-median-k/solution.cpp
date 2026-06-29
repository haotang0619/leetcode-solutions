// Figured out by myself
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int idx = -1, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == k) {
                idx = i;
                break;
            }
        }
        unordered_map<int, int> mp;
        int greaterCnt = 0;
        for(int i = idx; i < n; i++) {
            if(nums[i] > k) greaterCnt++;
            int len = i - idx + 1;
            int diff = len - greaterCnt * 2;
            mp[diff]++;
        }
        greaterCnt = 0;
        int ans = 0;
        for(int i = idx - 1; i >= -1; i--) {
            int len = idx - i - 1;
            int diff = len - greaterCnt * 2;
            ans += mp[-diff] + mp[-diff + 1];
            if(i >= 0 && nums[i] > k) greaterCnt++;
        }
        return ans;
    }
};
