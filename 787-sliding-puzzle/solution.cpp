class Solution {
public:
    string solved = "123450";
    int slidingPuzzle(vector<vector<int>>& board) {
        string now = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) now += ('0' + board[i][j]);
        }
        unordered_set<string> vis;
        vis.insert(now);
        queue<pair<int, string>> qu;
        qu.push({0, now});
        while(!qu.empty()) {
            auto [d, u] = qu.front();
            qu.pop();
            if(u == solved) return d;
            int i = 0, j = 0;
            for(i = 0; i < 2; i++) {
                for(j = 0; j < 3; j++) {
                    if(u[i * 3 + j] == '0') break;
                }
                if(j < 3 && u[i * 3 + j] == '0') break;
            }
            string v = u;
            swap(v[j], v[j + 3]);
            if(!vis.contains(v)) {
                vis.insert(v);
                qu.push({d + 1, v});
            }
            if(j > 0) {
                string v1 = u;
                swap(v1[i * 3 + j], v1[i * 3 + j - 1]);
                if(!vis.contains(v1)) {
                    vis.insert(v1);
                    qu.push({d + 1, v1});
                }
            }
            if(j < 2) {
                string v1 = u;
                swap(v1[i * 3 + j], v1[i * 3 + j + 1]);
                if(!vis.contains(v1)) {
                    vis.insert(v1);
                    qu.push({d + 1, v1});
                }
            }
        }
        return -1;
    }
};
