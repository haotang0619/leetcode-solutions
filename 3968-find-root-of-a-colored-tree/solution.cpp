class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<vector<int>> e(n);
        for(auto& x : edges) e[x[0]].push_back(x[1]), e[x[1]].push_back(x[0]);
        int root = -1;
        for(int i = 0; i < n; i++) {
            char col = colors[i], p, c;
            if(col == 'R') p = 'W', c = 'B';
            else if(col == 'W') p = 'B', c = 'R';
            else p = 'R', c = 'W';
            int cntp = 0, cntc = 0;
            for(auto& x : e[i]) {
                if(colors[x] == col) return -1;
                else if(colors[x] == p) cntp++;
                else cntc++;
            }
            if(cntp > 1 || cntc > 2) return -1;
            if(cntp == 0) {
                if(root == -1) root = i;
                else return -1;
            }
        }
        return root;
    }
};
