class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for(int k = 2; k <= n; k++) {
            int quo = n / k, rem = n % k;
            ans = max(ans, (int)pow(quo, k - rem) * (int)pow(quo + 1, rem));
        }
        return ans;
    }
};
