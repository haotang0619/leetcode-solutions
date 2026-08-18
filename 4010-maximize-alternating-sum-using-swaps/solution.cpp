class DSU {
public:
    vector<int> dsu;

    DSU(int n) : dsu(n) {
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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        DSU dsu(n);
        for(auto& swap : swaps) {
            int i = swap[0], j = swap[1];
            dsu.unite(i, j);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[dsu.find(i)].push_back(i);
        long long ans = 0;
        for(auto& [_, gp] : mp) {
            int odd = 0, even = 0;
            vector<int> v;
            for(auto& x : gp) {
                if(x & 1) odd++;
                else even++;
                v.push_back(nums[x]);
            }
            sort(v.rbegin(), v.rend());
            for(int i = 0; i < v.size(); i++) {
                if(i < even) ans += v[i];
                else ans -= v[i];
            }
        }
        return ans;
    }
};
