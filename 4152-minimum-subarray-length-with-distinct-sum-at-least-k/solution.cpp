class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        long long sum = 0;
        unordered_map<int, int> mp;
        for(int i = 0, j = 0; j < n; j++) {
            if(++mp[nums[j]] == 1) sum += nums[j];
            while(mp[nums[i]] >= 2 || sum - nums[i] >= k) {
                if(--mp[nums[i]] == 0) sum -= nums[i++];
                else i++;
            }
            if(sum >= k) ans = min(ans, j - i + 1);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
