class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int ans = 0, m = s.size();
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) ans = max(ans, (s[i] - '0') * (s[j] - '0'));
        }
        return ans;
    }
};
