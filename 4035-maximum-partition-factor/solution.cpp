// Asked GPT for the ParityDSU DS
class ParityDSU {
public:
    vector<int> parent, parity;

    ParityDSU(int n) : parent(n), parity(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    pair<int, int> find(int x) {
        if (parent[x] == x) return {x, 0};
        auto [root, p] = find(parent[x]);
        parity[x] ^= p;
        parent[x] = root;
        return {parent[x], parity[x]};
    }
    
    bool unite(int a, int b, int w) {
        auto [ra, pa] = find(a);
        auto [rb, pb] = find(b);

        if (ra == rb) return ((pa ^ pb) == w);
        parent[rb] = ra;
        parity[rb] = pa ^ pb ^ w;
        return true;
    }
};

class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 2) return 0;
        
        vector<tuple<int, int, int>> v; // [d, i, j]
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                auto& p1 = points[i];
                auto& p2 = points[j];
                int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                v.push_back({d, i, j});
            }
        }
        sort(v.begin(), v.end());
        
        ParityDSU pdsu(n);
        for(auto& [d, i, j] : v) {
            if(!pdsu.unite(i, j, 1)) return d;
        }
        return get<0>(v.back());
    }
};
