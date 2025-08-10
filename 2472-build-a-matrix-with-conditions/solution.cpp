class Solution {
public:
    // Googled for topoSort
    void topoSort(vector<int> &order, vector<int> &seen, int now, vector<vector<int>> &edges, bool &cycle) {
        if(seen[now] >= 1) {
            if(seen[now] == 1) cycle = true;
            return;
        }
        
        seen[now] = 1;
        for(auto x : edges[now]) topoSort(order, seen, x, edges, cycle);
        seen[now] = 2;
        order.push_back(now);
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> e1(k + 1, vector<int>({})), e2(k + 1, vector<int>({}));
        for(auto x : rowConditions) e1[x[0]].push_back(x[1]);
        for(auto x : colConditions) e2[x[0]].push_back(x[1]);
        
        vector<int> order1, order2, seen1(k + 1, 0), seen2(k + 1, 0);
        bool cycle1 = false, cycle2 = false;
        for(int i = 1; i <= k; i++) {
            if(seen1[i] == 0) topoSort(order1, seen1, i, e1, cycle1);
            if(seen2[i] == 0) topoSort(order2, seen2, i, e2, cycle2);
        }
        if(cycle1 || cycle2) return vector<vector<int>>({});
        
        reverse(order1.begin(), order1.end());
        reverse(order2.begin(), order2.end());
        
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<pair<int, int>> v(k + 1, pair<int, int>({0, 0}));
        for(int i = 0; i < k; i++) v[order1[i]].first = i;
        for(int i = 0; i < k; i++) v[order2[i]].second = i;
        for(int i = 1; i <= k; i++) {
            auto [r, c] = v[i];
            ans[r][c] = i;
        }
        return ans;
    }
};
