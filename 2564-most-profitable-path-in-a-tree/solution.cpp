class Solution {
public:
    bool dfs1(vector<int>& path, int node, vector<vector<int>>& e, set<int>& visit) {
        if(node == 0) return true;
        for(auto x : e[node]) {
            if(visit.find(x) == visit.end()) {
                visit.insert(x);
                bool success = dfs1(path, x, e, visit);
                if(success) {
                    path.push_back(x);
                    return true;
                }
                visit.erase(x);
            }
        }
        return false;
    }

    void dfs2(vector<int>& path, int node, vector<vector<int>>& e, set<int>& visit, set<int>& visitByBob, int curr, int &income, int time, vector<int>& amount) {
        int cnt = 0;
        if(path.size() > time - 1) visitByBob.insert(path[time - 1]);
        for(auto x : e[node]) {
            if(visit.find(x) == visit.end()) {
                cnt++;
                int change = visitByBob.find(x) == visitByBob.end() ? amount[x] : 0;
                if(path.size() > time && path[time] == x) change /= 2;
                visit.insert(x);
                dfs2(path, x, e, visit, visitByBob, curr + change, income, time + 1, amount);
                visit.erase(x);
            }
        }
        if(path.size() > time - 1) visitByBob.erase(path[time - 1]);
        if(cnt == 0) income = max(curr, income);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> e;
        e.resize(amount.size(), {});
        for(auto x : edges) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        vector<int> path = {};
        set<int> visit1;
        visit1.insert(bob);
        dfs1(path, bob, e, visit1);
        path.push_back(bob);
        reverse(path.begin(), path.end());

        int income = INT_MIN;
        set<int> visit2 = {0};
        set<int> visit3;
        dfs2(path, 0, e, visit2, visit3, amount[0], income, 1, amount);
        return income;
    }
};
