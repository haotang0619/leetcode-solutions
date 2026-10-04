class Solution {
public:
    int minRotations(int n, string s) {
        int cost = 0, now = 0;
        for(int i = 0; i < n; i++) {
            int d1 = now, d2 = s[i] - '0', dist = abs(d1 - d2);
            cost += min(dist, 10 - dist), now = d2;
        }
        int ans = cost;
        for(int i = n - 2; i >= 0; i--) {
            int cost1 = cost;
            int d1 = i == 0 ? 0 : (s[i - 1] - '0');
            int d2 = s[i] - '0', d3 = s[n - 1] - '0';
            int dist1 = abs(d1 - d2), dist2 = abs(d1 - d3);
            cost1 += min(dist2, 10 - dist2) - min(dist1, 10 - dist1);
            ans = min(ans, cost1);
        }
        return ans;
    }
};
