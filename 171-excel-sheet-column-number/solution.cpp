class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size(), ans = 0;
        long long multiplier = 1;
        for(int i = n - 1; i >= 0; i--) {
            int shift = (int)(columnTitle[i]) - 'A';
            ans += (shift + 1) * (int)multiplier;
            multiplier *= 26;
        }
        return ans;
    }
};
