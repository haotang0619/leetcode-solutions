// Saw all hints and asked GPT
class SegTree {
public:
    struct Node {
        int mn = 0, mx = 0;
    };

    int n;
    vector<Node> st;
    vector<int> lazy;

    SegTree(int n) {
        st.resize(4 * n);
        lazy.assign(4 * n, 0);
    }

    void apply(int p, int v) {
        st[p].mn += v, st[p].mx += v, lazy[p] += v;
    }

    void push(int p) {
        if (!lazy[p]) return;
        apply(p << 1, lazy[p]);
        apply(p << 1 | 1, lazy[p]);
        lazy[p] = 0;
    }

    void pull(int p) {
        st[p].mn = min(st[p << 1].mn, st[p << 1 | 1].mn);
        st[p].mx = max(st[p << 1].mx, st[p << 1 | 1].mx);
    }

    void update(int p, int l, int r, int ql, int qr, int val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(p, val);
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        update(p << 1, l, m, ql, qr, val);
        update(p << 1 | 1, m + 1, r, ql, qr, val);
        pull(p);
    }

    int rightmostZero(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return -1;
        if (st[p].mn > 0 || st[p].mx < 0) return -1;
        if (l == r) return l;
        push(p);
        int m = (l + r) >> 1;
        int res = rightmostZero(p << 1 | 1, m + 1, r, ql, qr);
        if (res != -1) return res;
        return rightmostZero(p << 1, l, m, ql, qr);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[nums[i]].push_back(i);
        SegTree st(n);
        // Initial balance for l = 0.
        for (auto &[val, v] : pos) {
            int sign = (val & 1) ? 1 : -1;
            st.update(1, 0, n - 1, v[0], n - 1, sign);
        }
        unordered_map<int, int> ptr;
        int ans = 0;
        for (int l = 0; l < n; l++) {
            int r = st.rightmostZero(1, 0, n - 1, l, n - 1);
            if (r != -1) ans = max(ans, r - l + 1);
            int x = nums[l];
            int sign = (x & 1) ? 1 : -1;
            int idx = ptr[x]++;
            int nxt = (idx + 1 < (int)pos[x].size()) ? pos[x][idx + 1] : n;
            st.update(1, 0, n - 1, 0, nxt - 1, -sign);
        }
        return ans;
    }
};
