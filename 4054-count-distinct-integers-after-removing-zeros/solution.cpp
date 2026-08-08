class Solution {
public:
    long long traverse(long long memo[20][2][10], string& s, int pos, bool tight, int prev) {
        int n = s.size();
        if(pos == n) return 1;
        if(memo[pos][tight][prev] != 0) return memo[pos][tight][prev];
        long long ans = 0;
        int maxD = tight ? (s[pos] - '0') : 9;
        for(int d = 0; d <= maxD; d++) {
            bool nextTight = tight && (d == maxD);
            if(prev != 0 && d == 0) continue;
            ans += traverse(memo, s, pos + 1, nextTight, d);
        }
        return memo[pos][tight][prev] = ans;
    }
    
    long long countDistinct(long long n) {
        string s = to_string(n);
        long long memo[20][2][10];
        memset(memo, 0, sizeof(memo));
        return traverse(memo, s, 0, true, 0) - 1;
    }
};
