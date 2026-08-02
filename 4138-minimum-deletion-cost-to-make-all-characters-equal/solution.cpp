class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> cSum(26, 0);
        long long total = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            cSum[idx] += cost[i];
            total += cost[i];
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i < 26; i++) ans = min(ans, total - cSum[i]);
        return ans;
    }
};
