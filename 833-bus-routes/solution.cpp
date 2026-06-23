class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> e;
        for(int i = 0; i < routes.size(); i++) {
            for(auto &x : routes[i]) e[x].push_back(i);
        }
        queue<pair<int, int>> qu;
        qu.push({source, 0});
        unordered_set<int> vis1, vis2;
        vis1.insert(source);
        while(!qu.empty()) {
            auto [u, dist] = qu.front();
            qu.pop();
            for(auto &r : e[u]) {
                if(vis2.contains(r)) continue;
                vis2.insert(r);
                for(auto &v : routes[r]) {
                    if(v == target) return dist + 1;
                    if(vis1.contains(v)) continue;
                    vis1.insert(v);
                    qu.push({v, dist + 1});
                }
            }
        }
        return -1;
    }
};
