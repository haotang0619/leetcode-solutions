class Solution {
public:
    int getPopCnt(long long x) {
        int ans = 0;
        while(x > 1) {
            int cnt = 0;
            long long x1 = x;
            while(x1 > 0) {
                cnt += (x1 & 1);
                x1 >>= 1;
            }
            x = cnt;
            ans++;
        }
        return ans;
    }

    void build(vector<int> &tree, int node, int initIdx, int l, int r) {
        if (l == r) {
            tree[node] = l == initIdx ? 1 : 0;
        } else {
            int mid = (l + r) / 2;
            build(tree, node * 2, initIdx, l, mid);
            build(tree, node * 2 + 1, initIdx, mid + 1, r);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(vector<int> &tree, int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(tree, node * 2, l, mid, idx, val);
            else update(tree, node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    int query(vector<int> &tree, int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(tree, node * 2, l, mid, ql, qr) + query(tree, node * 2 + 1, mid + 1, r, ql, qr);
    }
    
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        map<int, vector<int>> trees;
        for(int i = 0; i < n; i++) {
            long long x = nums[i];
            int pcnt = getPopCnt(x);
            if(trees.find(pcnt) == trees.end()) {
                trees[pcnt] = vector<int>(4 * n, 0);
                build(trees[pcnt], 1, i, 0, n - 1);
            } else update(trees[pcnt], 1, 0, n - 1, i, 1);
        }

        vector<int> ans;
        for(auto q : queries) {
            long long type = q[0];
            if(type == 1) {
                long long l = q[1], r = q[2], k = q[3];
                if(trees.find(k) == trees.end()) ans.push_back(0);
                else ans.push_back(query(trees[k], 1, 0, n - 1, l, r));
            } else {
                long long idx = q[1], val = q[2];
                long long ori = nums[idx];
                int oriPcnt = getPopCnt(ori);
                int newPcnt = getPopCnt(val);
                nums[idx] = val;
                
                update(trees[oriPcnt], 1, 0, n - 1, idx, 0);
                if(trees.find(newPcnt) == trees.end()) {
                    trees[newPcnt] = vector<int>(4 * n, 0);
                    build(trees[newPcnt], 1, idx, 0, n - 1);
                } else update(trees[newPcnt], 1, 0, n - 1, idx, 1);
            }
        }
        return ans;
    }
};
