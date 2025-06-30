class Solution {
public:
    void dfs(string node, set<string> &seen, unordered_map<string, vector<string>> &edges, vector<string> &topo) {
        seen.insert(node);
        for(auto x : edges[node]) {
            if(seen.find(x) == seen.end()) dfs(x, seen, edges, topo);
        }
        topo.push_back(node);
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Build graph
        unordered_map<string, vector<string>> edges;
        int n = ingredients.size();
        for(int i = 0; i < n; i++) {
            string rec = recipes[i];
            if(edges.find(rec) == edges.end()) edges[rec] = {};
            for(auto ing : ingredients[i]) {
                if(edges.find(ing) == edges.end()) edges[ing] = {};
                edges[ing].push_back(rec);
            }
        }

        // Topo sort by DFS
        set<string> seen;
        vector<string> topo;
        for(auto x : edges) {
            string node = x.first;
            if(seen.find(node) == seen.end()) dfs(node, seen, edges, topo);
        }
        reverse(topo.begin(), topo.end());

        // Find ans
        vector<string> ans;
        set<string> supp;
        for(auto x : supplies) supp.insert(x);
        for(auto x : topo) {
            for(int i = 0; i < n; i++) {
                if(recipes[i] == x) {
                    bool flag = true;
                    for(auto y : ingredients[i]) {
                        if(supp.find(y) == supp.end()) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        ans.push_back(recipes[i]);
                        supp.insert(recipes[i]);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
