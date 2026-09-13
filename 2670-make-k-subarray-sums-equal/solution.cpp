class DSU {
public:
    vector<int> dsu;
    
    DSU(int n) : dsu(n) {
        iota(dsu.begin(), dsu.end(), 0);
    }

    int find(int x) {
        if(x == dsu[x]) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        dsu[find(b)] = find(a);
    }
};

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        DSU dsu(n);
        if(k == 1) dsu.dsu.assign(n, 0);
        else {
            for(int i = 0; i < n; i++) {
                int l = i, r = (i + k) % n;
                dsu.unite(l, r);
            }
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[dsu.find(i)].push_back(arr[i]);
        }
        long long ans = 0;
        for(auto& [_, v] : mp) {
            sort(v.begin(), v.end());
            int sz = v.size(), med = v[sz / 2];
            for(auto& num : v) ans += abs(med - num);
        }
        return ans;
    }
};
