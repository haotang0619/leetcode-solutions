// Saw all hints and asked GPT
class SegTree {
public:
    struct Node {
        int prod, cnt[5];
    };

    int n, k;
    vector<Node> tree;

    SegTree(vector<int>& init, int K) {
        n = init.size(), k = K;
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int>& init, int node, int l, int r) {
        if(l == r) {
            makeLeaf(tree[node], init[l]);
        } else {
            int m = (l + r) / 2;
            build(init, node * 2, l, m);
            build(init, node * 2 + 1, m + 1, r);
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            makeLeaf(tree[node], val);
        } else {
            int m = (l + r) / 2;
            if(idx <= m) update(node * 2, l, m, idx, val);
            else update(node * 2 + 1, m + 1, r, idx, val);
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if(l == r) return tree[node];
        if(ql <= l && r <= qr) return tree[node];
        
        int m = (l + r) / 2;
        // IMPORTANT: Early return to avoid querying the irrelevant subtree.
        if(qr <= m) return query(node * 2, l, m, ql, qr);
        if(ql > m) return query(node * 2 + 1, m + 1, r, ql, qr);
        
        Node left = query(node * 2, l, m, ql, qr);
        Node right = query(node * 2 + 1, m + 1, r, ql, qr);
        return merge(left, right);
    }

    Node query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }

    void makeLeaf(Node& leaf, int val) {
        int rem = val % k;
        memset(leaf.cnt, 0, sizeof(leaf.cnt));
        leaf.prod = rem, leaf.cnt[rem] = 1;
    }

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = left.prod * right.prod % k;
        for(int x = 0; x < k; x++) res.cnt[x] = left.cnt[x];
        for(int x = 0; x < k; x++) {
            int rem = left.prod * x % k;
            res.cnt[rem] += right.cnt[x];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegTree st(nums, k);
        vector<int> ans;
        int n = nums.size();
        for(auto& q : queries) {
            int idx = q[0], val = q[1], l = q[2], x = q[3];
            st.update(idx, val);
            ans.push_back(st.query(l, n - 1).cnt[x]);
        }
        return ans;
    }
};
