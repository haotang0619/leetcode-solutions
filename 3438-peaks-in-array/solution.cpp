class SegTree {
public:
    int n;
    vector<int> tree;
    
    SegTree(vector<int>& init) {
        n = init.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, init);
    }

    void build(int node, int l, int r, vector<int>& init) {
        if(l == r) tree[node] = init[l];
        else {
            int m = (l + r) / 2;
            build(node * 2, l, m, init);
            build(node * 2 + 1, m + 1, r, init);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) tree[node] = val;
        else {
            int m = (l + r) / 2;
            if(idx <= m) update(node * 2, l, m, idx, val);
            else update(node * 2 + 1, m + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(ql > r || qr < l) return 0;
        if(ql <= l && qr >= r) return tree[node];
        int m = (l + r) / 2;
        return query(node * 2, l, m, ql, qr) + query(node * 2 + 1, m + 1, r, ql, qr);
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> init(n, 0);
        for(int i = 1; i < n - 1; i++) {
            if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) init[i] = 1;
        }
        SegTree st(init);
        vector<int> ans;
        for(auto& query : queries) {
            int type = query[0];
            if(type == 1) {
                int l = query[1], r = query[2];
                ans.push_back(st.query(l + 1, r - 1));
            } else {
                int idx = query[1], val = query[2];
                nums[idx] = val;
                for(int i = idx - 1; i <= idx + 1; i++) {
                    if(i > 0 && i < n - 1) {
                        if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
                            st.update(i, 1);
                        } else st.update(i, 0);
                    }
                }
            }
        }
        return ans;
    }
};
