class Solution {
public:
    void dfs(int node, int &n_cnt, int &e_sum, vector<bool> &seen, vector<vector<int>>& e) {
        seen[node] = true;
        n_cnt++;
        e_sum += e[node].size();
        for(auto x : e[node]) {
            if(!seen[x]) dfs(x, n_cnt, e_sum, seen, e);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> e(n, vector<int>({}));
        for(auto x : connections) {
            int f = x[0], t = x[1];
            e[f].push_back(t);
            e[t].push_back(f);
        }
        int gp_cnt = 0, e_cnt = 0;
        vector<bool> seen(n, false);
        for(int i = 0; i < n; i++) {
            if(!seen[i]) {
                gp_cnt++;
                int e_sum = 0, n_cnt = 0;
                dfs(i, n_cnt, e_sum, seen, e);
                e_cnt += (e_sum / 2) - (n_cnt - 1);
            }
        }
        return (gp_cnt - 1) <= e_cnt ? gp_cnt - 1 : -1;
    }
};
