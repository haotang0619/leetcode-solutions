class SegTree {
public:
    vector<int> tree;

    SegTree(vector<int> &init) {
        int n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int> &init, int node, int l, int r) {
        if (l == r) {
            tree[node] = init[l];
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    int firstGreater(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql || tree[node] <= val) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left = firstGreater(node * 2, l, mid, ql, qr, val);
        if (left != -1) return left;
        return firstGreater(node * 2 + 1, mid + 1, r, ql, qr, val);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegTree st = SegTree(heights);
        vector<int> ans;
        for(auto &q : queries) {
            if(q[0] == q[1]) {
                ans.push_back(q[0]);
                continue;
            }
            int i = min(q[0], q[1]), j = max(q[0], q[1]);
            if(heights[j] > heights[i]) {
                ans.push_back(j);
                continue;
            }
            ans.push_back(st.firstGreater(1, 0, n - 1, j + 1, n - 1, heights[i]));
        }
        return ans;
    }
};
