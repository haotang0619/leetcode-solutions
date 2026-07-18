class DSU {
public:
    vector<int> dsu;
    vector<long long> sum;

    DSU(vector<int>& nums) {
        int n = nums.size();
        sum.assign(nums.begin(), nums.end());
        dsu.resize(n);
        iota(dsu.begin(), dsu.end(), 0);
    }

    int find(int x) {
        if(dsu[x] == x) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unite(int a, int b) {
        sum[find(a)] += sum[find(b)];
        dsu[find(b)] = find(a);
    }

    long long getSum(int x) {
        return sum[find(x)];
    }
};

class Solution {
public:
    int mod = 1e9 + 7;

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return nums[a] > nums[b];
        });
        
        DSU dsu(nums);
        long long ans = 0;
        for(auto& i : indices) {
            int val = nums[i];
            queue<int> qu;
            qu.push(i);
            while(!qu.empty()) {
                int u = qu.front();
                qu.pop();
                int v1 = u - 1, v2 = u + 1;
                if(v1 >= 0 && nums[v1] >= val && dsu.find(u) != dsu.find(v1)) {
                    dsu.unite(u, v1);
                    qu.push(v1);
                }
                if(v2 < n && nums[v2] >= val && dsu.find(u) != dsu.find(v2)) {
                    dsu.unite(u, v2);
                    qu.push(v2);
                }
            }
            ans = max(ans, dsu.getSum(i) * val);
        }
        return ans % mod;
    }
};
