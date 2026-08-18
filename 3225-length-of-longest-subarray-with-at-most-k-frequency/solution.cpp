class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> freq;
        for(int l = 0, r = 0; r < n; r++) {
            int now = nums[r];
            freq[now]++;
            while(freq[now] > k) freq[nums[l++]]--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
