class DSU {
public:
    unordered_map<int, int> st;

    int find(int x) {
        if(!st.contains(x)) st[x] = x;
        if(st[x] == x) return x;
        return st[x] = find(st[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        st[b] = a;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        DSU dsu = DSU();
        for(auto &x : nums) {
            int minFac = -1;
            for(int i = 2; i * i <= x; i++) {
                if(x % i != 0) continue;
                if(minFac == -1) minFac = i;
                int j = x / i;
                dsu.unite(minFac, i);
                if(i != j) dsu.unite(minFac, j);
            }
            if(minFac == -1) minFac = x;
            dsu.unite(minFac, x);
        }
        unordered_map<int, int> mp;
        int ans = -1;
        for(auto &x : nums) {
            mp[dsu.find(x)]++;
            ans = max(ans, mp[dsu.find(x)]);
        }
        return ans;
    }
};
