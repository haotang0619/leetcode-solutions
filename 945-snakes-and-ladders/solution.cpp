class Solution {
public:
    int INF = 1e6;
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), i = 1;
        vector<vector<int>> edges(n * n + 1);
        
        // Build edges:
        for(int x = n - 1, dir = 1; x >= 0; x--, dir *= -1) {
            for(int j = 0; j < n; j++, i++) {
                int y = dir == 1 ? j : n - 1 - j;
                int next = board[x][y];
                if(next == -1) {
                    // Dice:
                    for(int prev = max(i - 6, 1); prev < i; prev++) {
                        edges[prev].push_back(i);
                    }
                } else {
                    // Snake or Ladder:
                    for(int prev = max(i - 6, 1); prev < i; prev++) {
                        edges[prev].push_back(next);
                    }
                }
            }
        }

        // BFS
        vector<int> dist(n * n + 1, INF);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(auto x : edges[now]) {
                if(dist[x] == INF) {
                    dist[x] = dist[now] + 1;
                    q.push(x);
                }
            }
        }
        return dist[n * n] == INF ? -1 : dist[n * n];
    }
};
