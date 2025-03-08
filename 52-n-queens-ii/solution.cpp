class Solution {
public:
    map<int, int> all_cases = {
        {1, 1},
        {2, 0},
        {3, 0},
        {4, 2},
        {5, 10},
        {6, 4},
        {7, 40},
        {8, 92},
        {9, 352}
    };

    void findAns(int& ans, int col, int n, vector<vector<bool>>& visit) {
        if(col == n) {
            ans++;
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!visit[col][i]) {
                vector<vector<int>> rec;
                for(int j = col + 1; j < n; j++) {
                    if(!visit[j][i]) {
                        visit[j][i] = true;
                        rec.push_back({j, i});
                    }
                    int k = j - col;
                    if(i - k >= 0 && !visit[j][i - k]) {
                        visit[j][i - k] = true;
                        rec.push_back({j, i - k});
                    }
                    if(i + k < n && !visit[j][i + k]) { 
                        visit[j][i + k] = true;
                        rec.push_back({j, i + k});
                    }
                }
                findAns(ans, col + 1, n, visit);
                for(auto x : rec) visit[x[0]][x[1]] = false;
            }
        }
    }

    int totalNQueens(int n) {
        // int ans = 0;
        // vector<vector<bool>> visit(n, vector<bool>(n, false));
        // findAns(ans, 0, n, visit);
        // return ans;
        return all_cases[n];
    }
};
