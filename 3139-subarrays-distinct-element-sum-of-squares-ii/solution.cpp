// Asked AI for hints and SegTree update idea
const int mod = 1e9 + 7;
class SegTreeLazy {
public:
    int n;
    vector<long long> sum, sqSum, lazy;

    SegTreeLazy(int sz) : n(sz) {
        sum.assign(4 * n, 0), sqSum.assign(4 * n, 0), lazy.assign(4 * n, 0);
    }

    void apply(int node, int l, int r, long long v) {
        long long len = r - l + 1;
        sqSum[node] = (sqSum[node] + 2 * v * sum[node] % mod + len * (v * v % mod)) % mod;
        sum[node] = (sum[node] + len * v) % mod;
        lazy[node] = (lazy[node] + v) % mod;
    }

    void push(int node, int l, int r) {
        if(lazy[node] == 0 || l == r) return;
        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);
        lazy[node] = 0;
    }

    void rangeUpdate(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = (l + r) / 2;
        rangeUpdate(node * 2, l, mid, ql, qr);
        rangeUpdate(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % mod;
        sqSum[node] = (sqSum[node * 2] + sqSum[node * 2 + 1]) % mod;
    }

    void rangeUpdate(int l, int r) {
        rangeUpdate(1, 0, n - 1, l, r);
    }

    long long query() {
        return sqSum[1];
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        vector<int> lastPos(mx + 1, -1);
        long long ans = 0;
        SegTreeLazy stl(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i], p = lastPos[num] + 1;
            stl.rangeUpdate(p, i);
            ans = (ans + stl.query()) % mod;
            lastPos[num] = i;
        }
        return ans;
    }
};
