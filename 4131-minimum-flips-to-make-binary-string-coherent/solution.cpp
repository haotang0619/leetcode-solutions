class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if(n <= 2) return 0;
        
        int ans = INT_MAX, zcnt = 0, ocnt = 0, f = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') zcnt++;
            else ocnt++;
            if(i == 0 || i == n - 1) {
                if(s[i] == '0') f++;
            } else if(s[i] == '1') f++;
        }
        
        // 1. Flip all 0 to 1 OR Flip all 1 to 0 but keep a single 1
        ans = min(zcnt, max(ocnt - 1, 0));
        // 2. Keep 1 only in the head and end
        ans = min(ans, f);
        
        return ans;
    }
};
