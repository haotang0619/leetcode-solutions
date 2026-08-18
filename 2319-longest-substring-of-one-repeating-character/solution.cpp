class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) tree[node] = val;
        else {
            int mid = (l + r) / 2;
            if(idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(ql > r || qr < l) return 0;
        if(ql <= l && qr >= r) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        map<int, int> runs;
        int prev = -1, idx = -1, cnt = 0, n = s.size();
        for(int i = 0; i <= n; i++) {
            int now = (i == n) ? -1 : (s[i] - 'a');
            if(now != prev) {
                if(cnt > 0) runs[idx] = cnt;
                idx = i, cnt = 0;
            }
            prev = now, cnt++;
        }

        SegTree tree(n);
        for(auto& [idx, cnt] : runs) tree.update(idx, cnt);

        auto updateRun = [&](int idx, int cnt) {
            if (cnt == 0) runs.erase(idx), tree.update(idx, 0);
            else runs[idx] = cnt, tree.update(idx, cnt);
        };

        int m = queryIndices.size();
        vector<int> ans(m, 0);
        for(int i = 0; i < m; i++) {
            int qidx = queryIndices[i];
            char c1 = s[qidx], c2 = queryCharacters[i];
            int i1 = c1 - 'a', i2 = c2 - 'a';
            if(c1 != c2) {
                auto it = runs.lower_bound(qidx);
                if(it == runs.begin()) {
                    if(runs[qidx] > 1) {
                        updateRun(qidx + 1, runs[qidx] - 1);
                        updateRun(qidx, 1);
                    } else {
                        if(qidx + 1 < n && s[qidx + 1] == c2) {
                            updateRun(qidx, 1 + runs[qidx + 1]);
                            updateRun(qidx + 1, 0);
                        }
                    }
                } else {
                    auto [idx, cnt] = *(--it);
                    int l = idx, r = idx + cnt - 1;
                    // [l..r] < qidx
                    if(r < qidx) {
                        if(runs[qidx] > 1) {
                            if(s[qidx - 1] == c2) {
                                updateRun(l, cnt + 1);
                                updateRun(qidx + 1, runs[qidx] - 1);
                                updateRun(qidx, 0);
                            } else {
                                updateRun(qidx + 1, runs[qidx] - 1);
                                updateRun(qidx, 1);
                            }
                        } else {
                            if(s[qidx - 1] == c2 && qidx + 1 < n && s[qidx + 1] == c2) {
                                updateRun(l, cnt + 1 + runs[qidx + 1]);
                                updateRun(qidx, 0);
                                updateRun(qidx + 1, 0);
                            } else if(s[qidx - 1] == c2) {
                                updateRun(l, cnt + 1);
                                updateRun(qidx, 0);
                            } else if(qidx + 1 < n && s[qidx + 1] == c2) {
                                updateRun(qidx, 1 + runs[qidx + 1]);
                                updateRun(qidx + 1, 0);
                            }
                        }
                    } else if(r == qidx) {
                        updateRun(l, cnt - 1);
                        if(qidx + 1 < n && s[qidx + 1] == c2) {
                            updateRun(qidx, 1 + runs[qidx + 1]);
                            updateRun(qidx + 1, 0);
                        } else updateRun(qidx, 1);
                    } else {
                        updateRun(l, qidx - l);
                        updateRun(qidx, 1);
                        updateRun(qidx + 1, r - qidx);
                    } 
                }
                s[qidx] = c2;
            }
            ans[i] = tree.query(0, n - 1);
        }
        return ans;
    }
};
