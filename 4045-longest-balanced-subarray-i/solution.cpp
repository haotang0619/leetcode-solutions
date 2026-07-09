class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        vector<int> sum(n, 0);
        for(auto& [x, v] : mp) {
            reverse(v.begin(), v.end());
            for(int i = v.back(); i < n; i++) sum[i] += (x % 2 == 0 ? 1 : -1);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(sum[j] == 0) ans = max(ans, j - i + 1);
            }
            mp[nums[i]].pop_back();
            int next = mp[nums[i]].empty() ? n : mp[nums[i]].back();
            for(int j = i; j < next; j++) sum[j] -= (nums[i] % 2 == 0 ? 1 : -1);
        }
        return ans;
    }
};
