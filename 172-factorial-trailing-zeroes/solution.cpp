class Solution {
public:
    int trailingZeroes(int n) {
        int div = 5;
        int ans = 0;
        while(n >= div) {
            ans += n / div;
            div *= 5;
        }
        return ans;
    }
};
