class Solution {
public:
    void findAns(vector<vector<int>>& ans, vector<int>& path, vector<vector<int>>& graph, int u) {
        int n = graph.size();
        if(u == n - 1) {
            ans.push_back(path);
            return;
        }
        unordered_set<int> st(path.begin(), path.end());
        for(auto &v : graph[u]) {
            if(st.contains(v)) continue;
            path.push_back(v);
            findAns(ans, path, graph, v);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path = {0};
        findAns(ans, path, graph, 0);
        return ans;
    }
};
