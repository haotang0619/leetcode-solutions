class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int dist = min(j - i, abs(x - i) + 1 + abs(j - y));
                dist = min(dist, abs(y - i) + 1 + abs(x - j));
                ans[dist - 1] += 2;
            }
        }
        return ans;
    }
};
