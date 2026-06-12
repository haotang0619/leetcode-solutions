class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), now = 1, ans = 0;
        for(int i = 0, j = 0; j < n; j++) {
            now *= nums[j];
            while(i <= j && now >= k) now /= nums[i++];
            ans += j - i + 1;
        }
        return ans;
    }
};
