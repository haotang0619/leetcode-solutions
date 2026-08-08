class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
            return abs(a) > abs(b);
        });
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long now = nums[i];
            if(i < (n + 1) / 2) ans += now * now;
            else ans -= now * now;
        }
        return ans;
    }
};
