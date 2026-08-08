class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int> f;
        int n = nums.size();
        for(int i = 1; i <= n / i; i++) {
            if(n % i == 0) {
                f.push_back(i);
                int j = n / i;
                if(i != j) f.push_back(j);
            }
        }
        sort(f.begin(), f.end());
        
        int ans = 0;
        for(int i = 0; i < f.size(); i++) {
            // [inv_cnt, mn, mx]
            vector<tuple<int, int, int>> dp(n / f[i]);
            for(int j = 0; j < n / f[i]; j++) {
                int inv = 0, mn = INT_MAX, mx = INT_MIN;
                int l = j * f[i], r = (j + 1) * f[i];
                for(int k = l; k < r; k++) {
                    mn = min(mn, nums[k]), mx = max(mx, nums[k]);
                    if(k + 1 < r && nums[k] > nums[k + 1]) inv++;
                    if(k == r - 1 && nums[k] > nums[l]) inv++;
                }
                dp[j] = {inv, mn, mx};
            }
            
            bool valid = true;
            for(int j = 0; j < dp.size(); j++) {
                auto& [inv1, mn1, mx1] = dp[j];
                if(inv1 > 1) {
                    valid = false;
                    break;
                }
                if(j + 1 < dp.size()) {
                    auto& [inv2, mn2, mx2] = dp[j + 1];
                    if(mx1 > mn2) {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) ans += f[i];
        }
        return ans;
    }
};
