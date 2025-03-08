class Solution {
public:
    int climbStairs(int n) {
        int ans = 1, prev = 1;
        while(--n > 0) {
            int tmp = prev;
            prev = ans;
            ans += tmp;
        }
        return ans;
    }
};
