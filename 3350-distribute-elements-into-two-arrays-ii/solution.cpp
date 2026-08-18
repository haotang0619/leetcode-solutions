class SegTree {
public:
    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] += val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int idx = 0;
        unordered_map<int, int> mp;
        for(auto& x : tmp) {
            if(mp.contains(x)) continue;
            mp[x] = idx++;
        }
        vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
        SegTree st1(idx), st2(idx);
        st1.update(mp[nums[0]], 1), st2.update(mp[nums[1]], 1);
        int n = nums.size();
        for(int i = 2; i < n; i++) {
            int cnt1 = st1.query(mp[nums[i]] + 1, idx);
            int cnt2 = st2.query(mp[nums[i]] + 1, idx);
            bool toArr2 = cnt1 < cnt2 || (cnt1 == cnt2 && arr2.size() < arr1.size());
            if(toArr2) {
                arr2.push_back(nums[i]);
                st2.update(mp[nums[i]], 1);
            } else {
                arr1.push_back(nums[i]);
                st1.update(mp[nums[i]], 1);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
