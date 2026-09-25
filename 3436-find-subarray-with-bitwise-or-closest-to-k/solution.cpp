class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int pSum[n + 1][31];
        memset(pSum, 0, sizeof(pSum));
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 31; j++) {
                int b = 1 << j;
                pSum[i][j] = pSum[i - 1][j] + ((nums[i - 1] & b) != 0);
            }
        }

        auto getOrVal = [&](int l, int r) {
            int val = 0;
            for(int j = 0; j < 31; j++) {
                int b = 1 << j, diff = pSum[r + 1][j] - pSum[l][j];
                if(diff > 0) val |= b;
            }
            return val;
        };

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            while(l != r) {
                int m = l + (r - l) / 2, val = getOrVal(i, m);
                if(val > k) r = m;
                else l = m + 1;
            }
            ans = min(ans, abs(getOrVal(i, l) - k));
            if(l > i) ans = min(ans, abs(getOrVal(i, l - 1) - k));
        }
        return ans;
    }
};
