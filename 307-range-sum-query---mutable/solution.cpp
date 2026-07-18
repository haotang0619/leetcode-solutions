class SegTree {
public:
    int n;
    vector<int> tree;
    
    SegTree(vector<int>& init) {
        n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }
    
    void build(vector<int>& init, int node, int l, int r) {
        if(l == r) tree[node] = init[l];
        else {
            int m = (l + r) / 2;
            build(init, node * 2, l, m);
            build(init, node * 2 + 1, m + 1, r);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
    
    void update(int node, int l, int r, int idx, int val) {
        if(l == r) tree[node] = val;
        else {
            int m = (l + r) / 2;
            if (idx <= m) update(node * 2, l, m, idx, val);
            else update(node * 2 + 1, m + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
    
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        return query(node * 2, l, m, ql, qr) + query(node * 2 + 1, m + 1, r, ql, qr);
    }
    
    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

class NumArray {
public:
    SegTree* st;
    
    NumArray(vector<int>& nums) {
        st = new SegTree(nums);
    }
    
    void update(int index, int val) {
        st->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st->query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
