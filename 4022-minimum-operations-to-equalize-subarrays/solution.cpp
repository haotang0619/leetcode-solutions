class MergeSortTree {
public:
    int n;
    vector<vector<int>> tree;
    vector<vector<long long>> prefix;

    MergeSortTree(vector<int> &nums) {
        n = nums.size();
        tree.resize(4 * n);
        prefix.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void build(vector<int> &nums, int node, int l, int r) {
        if (l == r) {
            tree[node].push_back(nums[l]);
        } else {
            int mid = (l + r) / 2;
            build(nums, node * 2, l, mid);
            build(nums, node * 2 + 1, mid + 1, r);
            tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
            merge(tree[node * 2].begin(), tree[node * 2].end(),
                  tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
                  tree[node].begin()
            );
        }
        prefix[node].resize(tree[node].size() + 1);
        for (int i = 0; i < tree[node].size(); i++) {
            prefix[node][i + 1] = prefix[node][i] + tree[node][i];
        }
    }

    int countLE(int node, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
        }
        int mid = (l + r) / 2;
        return countLE(node * 2, l, mid, ql, qr, x) + countLE(node * 2 + 1, mid + 1, r, ql, qr, x);
    }

    int countLE(int l, int r, int x) {
        return countLE(1, 0, n - 1, l, r, x);
    }

    // sum of values <= x in [ql, qr]
    long long sumLE(int node, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) {
            int idx = upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
            return prefix[node][idx];
        }
        int mid = (l + r) / 2;
        return sumLE(node * 2, l, mid, ql, qr, x) + sumLE(node * 2 + 1, mid + 1, r, ql, qr, x);
    }

    long long sumLE(int l, int r, int x) {
        return sumLE(1, 0, n - 1, l, r, x);
    }

    // sum of entire range [l, r]
    long long sum(int l, int r) {
        return sumLE(l, r, INT_MAX);
    }
};

class Solution {
public:
    void binarySearchMedium(vector<long long>& ans, MergeSortTree& mst, int& k, vector<tuple<int, int, int>>& validQueries, int vql, int vqr, int ql, int qr) {
        int qmid = ql + (qr - ql) / 2, n = mst.n;
        if(ql == qr) {
            for(int idx = vql; idx <= vqr; idx++) {
                auto& [i, l, r] = validQueries[idx];
                long long len = r - l + 1;
                long long leftCnt = mst.countLE(l, r, qmid);
                long long leftSum = mst.sumLE(l, r, qmid);
                long long totalSum = mst.sum(l, r);
                long long rightCnt = len - leftCnt;
                long long rightSum = totalSum - leftSum;
                ans[i] = (qmid * leftCnt - leftSum + rightSum - qmid * rightCnt) / k;
            }
            return;
        }

        int newLeftVqr = vql - 1;
        for(int idx = vql; idx <= vqr; idx++) {
            auto& [i, l, r] = validQueries[idx];
            int half = (r - l) / 2 + 1;
            int cnt = mst.countLE(l, r, qmid);
            if(cnt >= half) swap(validQueries[++newLeftVqr], validQueries[idx]);
        }

        if(newLeftVqr >= vql) {
            binarySearchMedium(ans, mst, k, validQueries, vql, newLeftVqr, ql, qmid);
        }
        if(newLeftVqr < vqr) {
            binarySearchMedium(ans, mst, k, validQueries, newLeftVqr + 1, vqr, qmid + 1, qr);
        }
    }

    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> gaps(n, 0);
        for(int i = 0; i < n - 1; i++) {
            int rem = (nums[i + 1] - nums[i]) % k;
            gaps[i] = rem < 0 ? (rem + k) : rem;
        }
        vector<long long> pSumGaps(n + 1, 0);
        for(int i = 1; i <= n; i++) pSumGaps[i] = pSumGaps[i - 1] + gaps[i - 1];

        int m = queries.size();
        vector<tuple<int, int, int>> validQueries; // [idx, l, r]
        vector<long long> ans(m, -1);
        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            long long rangeGapSum = pSumGaps[r] - pSumGaps[l];
            if(rangeGapSum > 0) continue;
            validQueries.push_back({i, l, r});
        }

        int vqsz = validQueries.size();
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        MergeSortTree mst(nums);
        binarySearchMedium(ans, mst, k, validQueries, 0, vqsz - 1, mn, mx);
        return ans;
    }
};
