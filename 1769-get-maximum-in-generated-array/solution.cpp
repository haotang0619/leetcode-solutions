class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        vector<int> v(n + 1, 0);
        v[1] = 1;
        int ans = 1;
        for(int i = 2; i <= n; i++) {
            v[i] = i % 2 ? v[i / 2] + v[i / 2 + 1] : v[i / 2];
            ans = max(ans, v[i]);
        }
        return ans;
    }
};
