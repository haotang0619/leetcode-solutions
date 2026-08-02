class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long ans = s + m;
        if(n == 2) return ans;
        return ans + (long long)(m - 1) * ((n - 2) / 2);
    }
};
