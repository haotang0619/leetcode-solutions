class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0, sum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            if(i >= k) {
                if(--mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
                sum -= nums[i - k];
            }
            if(i >= k - 1 && mp.size() >= m) ans = max(ans, sum);
        }
        return ans;
    }
};
