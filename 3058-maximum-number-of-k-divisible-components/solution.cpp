class Solution {
public:
    int traverse(vector<unordered_map<int, int>>& childMod, vector<vector<int>>& e, vector<int>& values, int& k, int parent, int u) {
        int now = values[u] % k;
        for(auto& v : e[u]) {
            if(v == parent) continue;
            childMod[u][v] = traverse(childMod, e, values, k, u, v);
            now = (now + childMod[u][v]) % k;
        }
        return now;
    }

    int findAns(vector<unordered_map<int, int>>& childMod, int u, bool hasCount) {
        int ans = hasCount ? 0 : 1;
        for(auto& [v, mod] : childMod[u]) {
            if(mod == 0) ans += findAns(childMod, v, false);
            else ans += findAns(childMod, v, true);
        }
        return ans;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> e(n);
        for(auto& x : edges) e[x[0]].push_back(x[1]), e[x[1]].push_back(x[0]);
        vector<unordered_map<int, int>> childMod(n);
        traverse(childMod, e, values, k, -1, 0);
        return findAns(childMod, 0, false);
    }
};
