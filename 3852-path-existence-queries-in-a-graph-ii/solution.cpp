// Saw all hints, and used the first 2
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return nums[a] < nums[b];
        });
        for(auto& q : queries) {
            bool wasDifferent = q[0] != q[1];
            for(int i = 0; i < 2; i++) {
                q[i] = lower_bound(indices.begin(), indices.end(), q[i], [&](auto& idx, auto& val) {
                    return nums[idx] < nums[val];
                }) - indices.begin();
            }
            if(wasDifferent && q[0] == q[1]) q[1] = q[0] + 1;
            if(q[0] > q[1]) swap(q[0], q[1]);
        }
        sort(nums.begin(), nums.end());
        int m = log2(n) + 1;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for(int i = 0, j = 1; i < n; i++) {
            while(j < n && nums[j] - nums[i] <= maxDiff) j++;
            if(j - 1 > i && nums[j - 1] - nums[i] <= maxDiff) dp[i][0] = j - 1;
        }
        for(int j = 1; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(dp[i][j - 1] == INT_MAX) break;
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
        vector<int> ans;
        for(auto& q : queries) {
            int x = q[0], y = q[1];
            if(x == y) {
                ans.push_back(0);
                continue;
            }
            int step = 0;
            while(true) {
                int idx = lower_bound(dp[x].begin(), dp[x].end(), y) - dp[x].begin();
                if(idx == 0) {
                    if(dp[x][idx] == INT_MAX) step = -1;
                    else step += 1;
                    break;
                }
                step += (1 << (idx - 1));
                x = dp[x][idx - 1];
            }
            ans.push_back(step);
        }
        return ans;
    }
};
