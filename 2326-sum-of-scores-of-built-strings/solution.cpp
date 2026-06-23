// Saw all hints and learned Z-Algo
class Solution {
public:
    long long sumScores(string s) {
        int n = s.size(), l = 0, r = 0;
        long long ans = n;
        vector<int> z(n, 0);
        for(int i = 1; i < n; i++) {
            int j = 0, k = i;
            if(i <= r && i - l >= 1) {
                int prev = i - l;
                if(z[prev] + i <= r) {
                    z[i] = z[prev];
                    ans += z[i];
                    continue;
                } else j = r + 1 - i, k = r + 1;
            }
            while(k < n && s[j] == s[k]) j++, k++;
            z[i] = k - i, l = i, r = k - 1;
            ans += z[i];
        }
        return ans;
    }
};
