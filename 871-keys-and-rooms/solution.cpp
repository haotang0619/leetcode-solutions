class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt = 1, n = rooms.size();
        vector<int> vis(n, false);
        vis[0] = true;
        queue<int> qu;
        qu.push(0);
        while(!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for(auto &v: rooms[u]) {
                if(vis[v]) continue;
                vis[v] = true;
                cnt++;
                qu.push(v);
            }
        }
        return cnt == n;
    }
};
