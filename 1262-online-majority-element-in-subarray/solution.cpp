// When dealing with majority element problems, remember the voting algorithm.
using pii = pair<int, int>;
class SegTree {
public:
    int n;
    vector<pii> tree; // [candidate, count]

    SegTree(vector<int>& init) {
        n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<int>& init, int node, int l, int r) {
        if(l == r) {
            tree[node] = {init[l], 1};
        } else {
            int m = (l + r) / 2;
            build(init, node * 2, l, m);
            build(init, node * 2 + 1, m + 1, r);
            tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    pii query(int node, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        if(qr <= m) return query(node * 2, l, m, ql, qr);
        if(ql > m) return query(node * 2 + 1, m + 1, r, ql, qr);
        return merge(query(node * 2, l, m, ql, qr), query(node * 2 + 1, m + 1, r, ql, qr));
    }

    pii query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }

    pii merge(pii left, pii right) {
        auto& [candidate1, count1] = left;
        auto& [candidate2, count2] = right;
        if(candidate1 == candidate2) return {candidate1, count1 + count2};
        if(count1 >= count2) return {candidate1, count1 - count2};
        return {candidate2, count2 - count1};
    }
};

class MajorityChecker {
public:
    SegTree* st;
    vector<vector<int>> indices;

    MajorityChecker(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end()), n = arr.size();
        indices.resize(mx + 1);
        for(int i = 0; i < n; i++) indices[arr[i]].push_back(i);
        st = new SegTree(arr);
    }
    
    int query(int left, int right, int threshold) {
        auto [candidate, count] = st->query(left, right);
        auto l = lower_bound(indices[candidate].begin(), indices[candidate].end(), left);
        auto r = upper_bound(indices[candidate].begin(), indices[candidate].end(), right);
        return r - l >= threshold ? candidate : -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
