class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProducts(n, 0), suffixProducts(n, 0);
        prefixProducts[0] = nums[0];
        suffixProducts[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) {
            prefixProducts[i] = prefixProducts[i - 1] * nums[i];
        }
        for(int i = n - 2; i >= 0; i--) {
            suffixProducts[i] = suffixProducts[i + 1] * nums[i];
        }
        vector<int> ans(n, 0);
        ans[0] = suffixProducts[1];
        ans[n - 1] = prefixProducts[n - 2];
        for(int i = 1; i < n - 1; i++) {
            ans[i] = prefixProducts[i - 1] * suffixProducts[i + 1];
        }
        return ans;
    }
};
