class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, n = s.size();
        for(int i = 1; i <= n; i++) ans += ('z' - s[i - 1] + 1) * i;
        return ans;
    }
};
