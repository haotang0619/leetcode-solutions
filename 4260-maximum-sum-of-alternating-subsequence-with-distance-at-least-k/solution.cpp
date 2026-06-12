// Figured out by myself
class SegTree {
public:
    vector<long long> tree;

    SegTree(vector<long long> &init) {
        int n = init.size();
        tree.resize(4 * n);
        build(init, 1, 0, n - 1);
    }

    void build(vector<long long> &init, int node, int l, int r) {
        if (l == r) {
            tree[node] = init[l];
        } else {
            int mid = (l + r) / 2;
            build(init, node * 2, l, mid);
            build(init, node * 2 + 1, mid + 1, r);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, val);
            else update(node * 2 + 1, mid + 1, r, idx, val);
            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }
};

int maxVal = 1e5 + 7;
vector<long long> peaks(maxVal, 0), valleys(maxVal, 0);
SegTree* peakTree = new SegTree(peaks);
SegTree* valleyTree = new SegTree(valleys);

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < 4 * maxVal; i++) {
            peakTree->tree[i] = valleyTree->tree[i] = 0;
        }
        vector<pair<long long, long long>> posBest(n, {0, 0});
        for(int i = 0; i < n; i++) {
            if(i < k) posBest[i].first = posBest[i].second = nums[i]; 
            peakTree->update(1, 0, maxVal - 1, nums[i], posBest[i].first);
            valleyTree->update(1, 0, maxVal - 1, nums[i], posBest[i].second);
            if(i + k < n) {
                posBest[i + k].first = valleyTree->query(1, 0, maxVal - 1, 1, nums[i + k] - 1) + nums[i + k];
                posBest[i + k].second = peakTree->query(1, 0, maxVal - 1, nums[i + k] + 1, maxVal - 1) + nums[i + k];
            }
            ans = max(ans, max(posBest[i].first, posBest[i].second));
        }
        return ans;
    }
};
