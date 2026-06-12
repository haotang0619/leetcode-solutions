class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = INT_MAX, n = nums.size();
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(i == j) continue;
                int now = 0;
                for(int x = 0; x < n; x += 2) {
                    int mod1 = nums[x] % k;
                    now += min(abs(mod1 - i), k - abs(mod1 - i));
                    if(x + 1 < n) {
                        int mod2 = nums[x + 1] % k;
                        now += min(abs(mod2 - j), k - abs(mod2 - j));
                    }
                }
                ans = min(ans, now);
            }
        }
        return ans;
    }
};
