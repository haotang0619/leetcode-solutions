class Solution {
public:
    void dfs(int node, int &edgeIdx, int group, vector<int>& nums, vector<vector<int>> &gp, vector<pair<int, int>> &res, vector<vector<int>> &e, vector<bool> &seen) {
        seen[node] = true;
        gp[edgeIdx][node] = group;
        if(group == -1) res[edgeIdx].first ^= nums[node];
        else res[edgeIdx].second ^= nums[node];
        for(auto x : e[node]) {
            if(!seen[x]) dfs(x, edgeIdx, group, nums, gp, res, e, seen);
        }
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> gp(n - 1, vector<int>(n, 0));
        vector<pair<int, int>> res(n - 1, {0, 0});
        vector<vector<int>> e(n, vector<int>({}));
        for(int i = 0; i < n - 1; i++) {
            auto x = edges[i];
            int l = x[0], r = x[1];
            e[l].push_back(r);
            e[r].push_back(l);
        }
        for(int i = 0; i < n - 1; i++) {
            auto x = edges[i];
            int l = x[0], r = x[1];
            vector<bool> seen(n, false);
            seen[l] = seen[r] = true;
            dfs(l, i, -1, nums, gp, res, e, seen);
            dfs(r, i, 1, nums, gp, res, e, seen);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                int group1 = gp[i][edges[j][0]];
                int res1 = group1 == -1 ? res[i].second : res[i].first;
                int left = group1 == -1 ? res[i].first : res[i].second;
                int group2 = gp[j][edges[i][0]];
                int res2 = group2 == -1 ? res[j].second : res[j].first;
                int res3 = left ^ res2;
                int maxScore = max(max(res1, res2), res3);
                int minScore = min(min(res1, res2), res3);
                ans = min(ans, maxScore - minScore);
            }
        }
        return ans;
    }
};
