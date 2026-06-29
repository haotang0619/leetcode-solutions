class Solution {
public:
    int traverse1st(vector<unordered_map<int, int>>& rec, vector<vector<pair<int, bool>>>& e, int u, int prev) {
        int cnt = 0;
        for(auto [v, isRev] : e[u]) {
            if(v == prev) continue;
            int childCnt = traverse1st(rec, e, v, u) + (isRev ? 1 : 0);
            cnt += childCnt;
            rec[u][v] = childCnt;
        }
        return cnt;
    }

    void traverse2nd(vector<int>& ans, vector<unordered_map<int, int>>& rec, vector<vector<pair<int, bool>>>& e, int u, int prev, int others) {
        int cnt = 0;
        for(auto [v, isRev] : e[u]) {
            if(v == prev) continue;
            cnt += rec[u][v];
        }
        ans[u] = cnt + others;
        for(auto [v, isRev] : e[u]) {
            if(v == prev) continue;
            traverse2nd(ans, rec, e, v, u, others + cnt - rec[u][v] + (isRev ? 0 : 1));
        };
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, bool>>> e(n); // [node, isRevert]
        for(auto &x : edges) {
            e[x[0]].push_back({x[1], false});
            e[x[1]].push_back({x[0], true});
        }
        vector<unordered_map<int, int>> rec(n);
        traverse1st(rec, e, 0, -1);
        vector<int> ans(n);
        traverse2nd(ans, rec, e, 0, -1, 0);
        return ans;
    }
};
