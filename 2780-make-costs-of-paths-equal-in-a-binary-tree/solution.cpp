class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        vector<int> child(n, 0);
        for(int start = (n + 1) / 2; start >= 2; start /= 2) {
            for(int i = start; i < start * 2; i += 2) {
                int ci = cost[i - 1] + child[i - 1], cj = cost[i] + child[i];
                ans += abs(ci - cj);
                child[i / 2 - 1] = max(ci, cj);
            }
        }
        return ans;
    }
};
