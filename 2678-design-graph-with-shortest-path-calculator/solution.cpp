class Graph {
public:
    vector<vector<pair<int, int>>> e;

    Graph(int n, vector<vector<int>>& edges) {
        e.resize(n);
        for(auto &x : edges) e[x[0]].push_back({x[1], x[2]});
    }

    int dijkstra(int src, int tar) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(e.size(), INT_MAX);
        pq.push({0, src});
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            if(u == tar) return d;
            for(auto [v, d1] : e[u]) {
                if(d + d1 >= dist[v]) continue;
                dist[v] = d + d1;
                pq.push({dist[v], v});
            }
        }
        return -1;
    }
    
    void addEdge(vector<int> x) {
        e[x[0]].push_back({x[1], x[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
