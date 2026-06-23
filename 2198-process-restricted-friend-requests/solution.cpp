class DSU {
public:
    unordered_map<int, int> mp;

    int find(int x) {
        if(!mp.contains(x)) {
            mp[x] = x;
            return x;
        }
        if(mp[x] == x) return x;
        return mp[x] = find(mp[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        mp[b] = mp[a];
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU dsu = DSU();
        vector<bool> ans;
        for(auto &req : requests) {
            int a = dsu.find(req[0]), b = dsu.find(req[1]);
            bool valid = true;
            for(auto &res : restrictions) {
                int c = dsu.find(res[0]), d = dsu.find(res[1]);
                if(a == c && b == d || a == d && b == c) {
                    valid = false;
                    break;
                }
            }
            ans.push_back(valid);
            if(valid) dsu.unite(req[0], req[1]);
        }
        return ans;
    }
};
