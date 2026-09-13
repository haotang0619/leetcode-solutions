class SparseTable {
public:
    int n, K;
    vector<vector<int>> st;

    SparseTable(vector<int>& a) {
        n = a.size();
        K = __lg(n) + 1;
        st.resize(K, vector<int>(n));
        st[0] = a;
        for(int k = 1; k < K; k++) {
            for(int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query(int l, int r) {
        if (l > r) return 0;
        int k = __lg(r - l + 1);
        return gcd(st[k][l], st[k][r - (1 << k) + 1]);
    }

    int query(int l, int r, int ban) {
        if (ban < l || ban > r) return query(l, r);
        return gcd(query(l, ban - 1), query(ban + 1, r));
    }
};

class Solution {
public:
    int binarySearch(SparseTable& st, int ban, bool findLast) {
        int n = st.n, l = 0, r = n - 2;
        while (l < r) {
            int m = findLast ? l + (r - l + 1) / 2 : l + (r - l) / 2;
            int gcdl = st.query(0, m, ban);
            int gcdr = st.query(m + 1, n - 1, ban);
            if (gcdl == 0) gcdl = INT_MAX;
            if (gcdr == 0) gcdr = INT_MAX;

            if (findLast) {
                if (gcdl >= gcdr) l = m;
                else r = m - 1;
            } else {
                if (gcdl <= gcdr) r = m;
                else l = m + 1;
            }
        }
        return l;
    }

    int maxValidSplits(vector<int>& nums) {
        SparseTable st(nums);
        int ans = 0, n = st.n;

        for (int i = -1; i < n; i++) {
            int l = binarySearch(st, i, false);
            int r = binarySearch(st, i, true);

            if (st.query(0, l, i) != st.query(l + 1, n - 1, i)) continue;

            int score = r - l + 1;
            if (i >= l && i <= r) score--;
            ans = max(ans, score);
        }
        return ans;
    }
};
