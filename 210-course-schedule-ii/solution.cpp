class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> e(numCourses);
        vector<int> indeg(numCourses, 0);
        for(auto& x : prerequisites) {
            e[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        queue<int> qu;
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) qu.push(i);
        }
        vector<int> order;
        while(!qu.empty()) {
            auto u = qu.front();
            qu.pop();
            order.push_back(u);
            for(auto& v : e[u]) {
                if(--indeg[v] == 0) qu.push(v);
            }
        }
        return (order.size() == numCourses) ? order : vector<int>({});
    }
};
