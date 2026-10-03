class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, -1);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = max(tree[node], val);
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return -1;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> nums;
        for(auto& num : nums1) nums.push_back(num);
        for(auto& num : nums2) nums.push_back(num);
        for(auto& q : queries) nums.insert(nums.end(), {q[0], q[1]});
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        int m = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++) mp[nums[i]] = i;

        int n1 = nums1.size(), n2 = queries.size();
        vector<int> ans(n2), indices1(n1), indices2(n2);
        iota(indices1.begin(), indices1.end(), 0);
        iota(indices2.begin(), indices2.end(), 0);
        sort(indices1.begin(), indices1.end(), [&](auto& a, auto& b) {
            return nums1[a] > nums1[b];
        });
        sort(indices2.begin(), indices2.end(), [&](auto& a, auto& b) {
            return queries[a][0] > queries[b][0];
        });

        SegTree st(m);
        int pos = 0;
        for(auto& idx2 : indices2) {
            int x = queries[idx2][0], y = queries[idx2][1];
            while(pos < n1) {
                int idx1 = indices1[pos];
                if(nums1[idx1] < x) break;
                int idx = mp[nums2[idx1]];
                st.update(idx, nums1[idx1] + nums2[idx1]);
                pos++;
            }
            ans[idx2] = st.query(mp[y], m - 1);
        }
        return ans;
    }
};
