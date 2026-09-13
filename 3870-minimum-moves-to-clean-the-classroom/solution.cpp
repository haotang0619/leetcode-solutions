class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        unordered_map<int, int> litters;
        int l = 0, s = -1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') s = i * n + j;
                else if(classroom[i][j] == 'L') litters[i * n + j] = l++;
            }
        }

        int mask = 1 << l;
        int dist[mask][energy + 1][m * n]; // [litters, energy, pos]
        fill_n(&dist[0][0][0], mask * (energy + 1) * m * n, INT_MAX);
        dist[0][energy][s] = 0;
        queue<tuple<int, int, int>> qu; // [litters, energy, pos]
        qu.push({0, energy, s});

        while(!qu.empty()) {
            auto [lit, e, u] = qu.front();
            qu.pop();
            
            int d = dist[lit][e][u];
            if(lit == mask - 1) return d;
            if(e == 0) continue;
            
            int ui = u / n, uj = u % n;
            for(auto& [x, y] : dir) {
                int vi = ui + x, vj = uj + y, v = vi * n + vj;
                if(vi < 0 || vi >= m || vj < 0 || vj >= n) continue;
                if(classroom[vi][vj] == 'X') continue;
                
                int newE = e - 1;
                if(classroom[vi][vj] == 'R') newE = energy;
                
                int newLit = lit;
                if(classroom[vi][vj] == 'L') newLit |= (1 << litters[v]);
                if(newE == 0 && newLit != mask - 1) continue;
                
                if(dist[newLit][newE][v] <= d + 1) continue;
                dist[newLit][newE][v] = d + 1;
                qu.push({newLit, newE, v});
            }
        }
        return -1;
    }
};
