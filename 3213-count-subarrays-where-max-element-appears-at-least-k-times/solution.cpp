class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int target = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int idx1 = 0, idx2 = 0, cnt = 0;
        while(idx2 < nums.size()) {
            while(cnt < k) {
                if(nums[idx2++] == target) cnt++;
                if(idx2 >= nums.size()) break;
            }
            while(cnt == k) {
                if(nums[idx1] == target) cnt--;
                ans += ((long long)nums.size() - (long long)idx2 + (long long)1);
                idx1++;
            }
        }
        return ans;
    }
};
