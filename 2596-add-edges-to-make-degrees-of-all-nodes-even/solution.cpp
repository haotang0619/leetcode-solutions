class Solution {
public:
    bool check(int n, vector<int> &candidates, vector<unordered_set<int>> &e) {
        if(candidates.size() == 0) return true;
        if(candidates.size() == 2) {
            int a = candidates[0], b = candidates[1];
            if(!e[a].contains(b)) return true;
            for(int i = 1; i <= n; i++) {
                if(i == a || i == b) continue;
                if(!e[i].contains(a) && !e[i].contains(b)) return true;
            }
            return false;
        }
        if(candidates.size() == 4) {
            int a = candidates[0], b = candidates[1], c = candidates[2], d = candidates[3];
            if(!e[a].contains(b) && !e[c].contains(d)) return true;
            if(!e[a].contains(c) && !e[b].contains(d)) return true;
            if(!e[a].contains(d) && !e[b].contains(c)) return true;
            return false;
        }
        return false;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> e(n + 1);
        vector<int> deg(n + 1, 0);
        for(auto &x : edges) {
            e[x[0]].insert(x[1]);
            e[x[1]].insert(x[0]);
            deg[x[0]]++, deg[x[1]]++;
        }
        vector<int> candidates;
        for(int i = 1; i <= n; i++) {
            if(deg[i] % 2 == 1) candidates.push_back(i);
        }
        return check(n, candidates, e);
    }
};
