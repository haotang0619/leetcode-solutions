class Solution {
public:
    int getTargets(vector<vector<int>>& e, int limit, int dist, int parent, int u) {
        if(dist > limit) return 0;
        if(dist == limit) return 1;
        int cnt = 1;
        for(auto& v : e[u]) {
            if(v == parent) continue;
            cnt += getTargets(e, limit, dist + 1, u, v);
        }
        return cnt;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> e1(n), e2(m);
        for(auto& x : edges1) e1[x[0]].push_back(x[1]), e1[x[1]].push_back(x[0]);
        for(auto& x : edges2) e2[x[0]].push_back(x[1]), e2[x[1]].push_back(x[0]);
        int mxCnt = 0;
        for(int i = 0; i < m; i++) mxCnt = max(mxCnt, getTargets(e2, k - 1, 0, -1, i));
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = mxCnt + getTargets(e1, k, 0, -1, i);
        return ans;
    }
};
