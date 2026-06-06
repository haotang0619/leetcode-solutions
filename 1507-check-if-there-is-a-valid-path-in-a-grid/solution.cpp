class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> e(m * n, vector<int>({}));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int st = grid[i][j];
                int idx = i * n + j;
                int left = -1, right = -1, top = -1, bottom = -1;
                if(idx - 1 > 0 && (idx - 1) % n < n - 1) left = idx - 1;
                if((idx + 1) % n > 0) right = idx + 1;
                if(idx - n > 0) top = idx - n;
                if(idx + n < m * n) bottom = idx + n;
                if((st == 1 || st == 3 || st == 5) && left != -1) {
                    int i1 = left / n, j1 = left % n;
                    int st1 = grid[i1][j1];
                    if(st1 == 1 || st1 == 4 || st1 == 6) e[idx].push_back(left);
                }
                if((st == 1 || st == 4 || st == 6) && right != -1) {
                    int i1 = right / n, j1 = right % n;
                    int st1 = grid[i1][j1];
                    if(st1 == 1 || st1 == 3 || st1 == 5) e[idx].push_back(right);
                }
                if((st == 2 || st == 5 || st == 6) && top != -1) {
                    int i1 = top / n, j1 = top % n;
                    int st1 = grid[i1][j1];
                    if(st1 == 2 || st1 == 3 || st1 == 4) e[idx].push_back(top);
                }
                if((st == 2 || st == 3 || st == 4) && bottom != -1) {
                    int i1 = bottom / n, j1 = bottom % n;
                    int st1 = grid[i1][j1];
                    if(st1 == 2 || st1 == 5 || st1 == 6) e[idx].push_back(bottom);
                }
            }
        }
        vector<bool> visit(m * n, false);
        visit[0] = true;
        stack<int> sk;
        sk.push(0);
        while(!sk.empty()) {
            int top = sk.top();
            sk.pop();
            for(auto x : e[top]) {
                if(x == m * n - 1) return true;
                if(!visit[x]) {
                    visit[x] = true;
                    sk.push(x);
                }
            }
        }
        return visit[m * n - 1];
    }
};
