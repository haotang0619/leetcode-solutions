class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int cost = 0;
            for(int pos = 0; pos < n / 2; pos++) {
                int l = (i + pos) % n, r = (i + n - 1 - pos + n) % n;
                char c1 = s[l], c2 = s[r];
                if(c1 == c2) continue;
                if(c1 > c2) swap(c1, c2);
                int cost1 = c2 - c1, cost2 = 26 - cost1;
                cost += min(cost1, cost2);
            }
            ans = min(ans, cost + i);
        }
        return ans;
    }
};
