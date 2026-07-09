class DSU {
public:
    vector<int> dsu;

    DSU(int n) {
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
    }

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        dsu[find(b)] = find(a);
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] <= maxDiff) dsu.unite(i - 1, i);
        }
        vector<bool> ans;
        for(auto& q : queries) ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
        return ans;
    }
};
