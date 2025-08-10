class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long> lcnt(n, 0);
        vector<long long> tcnt(n, 0);
        for(int i = 0; i < n; i++) {
            if(i > 0) lcnt[i] = lcnt[i - 1];
            if(s[i] == 'L') lcnt[i]++;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(i < n - 1) tcnt[i] = tcnt[i + 1];
            if(s[i] == 'T') tcnt[i]++;
        }
        long long ans1 = 0, ans2 = 0, ans3 = 0, maxGain = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'C') {
                ans1 += (lcnt[i] + 1) * tcnt[i];
                ans3 += lcnt[i] * (tcnt[i] + 1);
                ans2 += lcnt[i] * tcnt[i];
            }
            if(i < n - 1) maxGain = max(maxGain, lcnt[i] * tcnt[i + 1]);
        }
        return max(max(ans1, ans3), ans2 + maxGain);
    }
};
