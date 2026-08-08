class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 1;
        for(int i = 0; i < 2 * n - 1; i++) {
            int l, r, len;
            // i as middle
            if(i % 2 == 0) l = i / 2 - 1, r = i / 2 + 1, len = 1;
            // i & i + 1 as middle
            else l = i / 2, r = i / 2 + 1, len = 0;
            while(l >= 0 && r < n && s[l] == s[r]) len += 2, l--, r++;
            ans = max(ans, len);
            if(l < 0 || r >= n) {
                if(l >= 0 || r < n) ans = max(ans, len + 1);
                continue;
            }
            
            // try delete l
            int l1 = l - 1, r1 = r, len1 = len + 1;
            while(l1 >= 0 && r1 < n && s[l1] == s[r1]) len1 += 2, l1--, r1++;
            ans = max(ans, len1);

            // try delete r
            int l2 = l, r2 = r + 1, len2 = len + 1;
            while(l2 >= 0 && r2 < n && s[l2] == s[r2]) len2 += 2, l2--, r2++;
            ans = max(ans, len2);
        }
        return ans;
    }
};
