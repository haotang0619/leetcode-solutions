class SegTreeLazy {
public:
    int n;
    vector<long long> tree, lazy;
    vector<bool> isLazy;

    SegTreeLazy(int sz) {
        n = sz;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        isLazy.resize(4 * n, false);
    }

    void push(int node, int l, int r) {
        if (isLazy[node]) {
            tree[node] = (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[node * 2] = lazy[node];
                lazy[node * 2 + 1] = lazy[node];
                isLazy[node * 2] = isLazy[node * 2 + 1] = true;
            }
            isLazy[node] = false;
        }
    }

    void rangeUpdate(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[node] = val;
            isLazy[node] = true;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdate(node * 2, l, mid, ql, qr, val);
        rangeUpdate(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void rangeUpdate(int ql, int qr, int val) {
        rangeUpdate(1, 0, n - 1, ql, qr, val);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    long long query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int prev = 0, now = 0, n = nums.size(), m = queries.size();
        vector<tuple<int, int, int>> newQueries(m);
        for(int i = 0; i < m; i++) {
            newQueries.push_back({i, queries[i][0], queries[i][1]});
        }
        sort(newQueries.begin(), newQueries.end(), [](auto& a, auto& b) {
            return get<2>(a) < get<2>(b);
        });
        SegTreeLazy stl(n);
        vector<long long> ans(m);
        for(auto& q : newQueries) {
            auto& [i, l, r] = q;
            while(now <= r) {
                if(now > 0 && nums[now] < nums[now - 1]) {
                    stl.rangeUpdate(prev, now - 1, now);
                    prev = now;
                }
                if(now == r || now + 1 == n) {
                    stl.rangeUpdate(prev, now, now + 1);
                    now++;
                    break;
                }
                now++;
            }
            long long sum1 = stl.query(l, r), sum2 = (long long)(l + r) * (r - l + 1) / 2;
            ans[i] = sum1 - sum2;
        }
        return ans;
    }
};
