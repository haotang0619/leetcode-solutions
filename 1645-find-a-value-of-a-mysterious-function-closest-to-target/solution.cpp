class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size(), pSum[n + 1][32];
        memset(pSum, 0, sizeof(pSum));
        for(int i = 1; i <= n; i++) {
            for(int x = 0; x < 32; x++) {
                int b = 1 << x;
                pSum[i][x] = pSum[i - 1][x] + ((arr[i - 1] & b) != 0);
            }
        }

        auto getAnd = [&](int l, int r) {
            int res = 0;
            for(int x = 0; x < 32; x++) {
                if(pSum[r + 1][x] - pSum[l][x] == r - l + 1) res |= (1 << x);
            }
            return res;
        };

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            while(l < r) {
                int m = (l + r) / 2;
                if(getAnd(i, m) < target) r = m;
                else l = m + 1;
            }
            ans = min(ans, abs(getAnd(i, l) - target));
            if(l > i) ans = min(ans, abs(getAnd(i, l - 1) - target));
        }
        return ans;
    }
};
