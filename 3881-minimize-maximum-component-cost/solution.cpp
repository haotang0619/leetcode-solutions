class Solution {
public:
    int search(vector<int> &dis, int a) {
        if(dis[a] == a) return a;
        else{
            dis[a] = search(dis, dis[a]);
            return dis[a];
        }
    }
    
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        vector<int> sel;
        // Kruskal
        vector<int> dis(n);
        for(int i = 0; i < n; i++) dis[i] = i;
        for(auto x : edges) {
            int a = x[0], b = x[1], w = x[2];
            int disA = search(dis, a), disB = search(dis, b);
            if(disA != disB) {
                sel.push_back(w);
                dis[disA] = disB;
            }
            if(sel.size() == n - 1) break;
        }
        return k == n ? 0 : sel[n - k - 1];
    }
};
