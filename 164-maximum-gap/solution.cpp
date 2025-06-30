class Solution {
public:
    int maximumGap(vector<int>& nums) {
        for(long long i = 1; i <= 1e9; i *= 10) {
            vector<vector<int>> v(10, vector<int>());
            for(auto x : nums) {
                int digit = (x / i) % 10;
                v[digit].push_back(x);
            }
            int j = 0;
            for(auto x : v) for(auto y : x) nums[j++] = y;
        }
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            ans = max(ans, nums[i + 1] - nums[i]);
        }
        return ans;
    }
};
