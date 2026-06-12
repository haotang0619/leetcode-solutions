// Learned from GPT:
class SqrtDecomposition {
public:
    int n;
    int blockSize;
    int blockCount;

    vector<long long> arr;
    vector<long long> lazy;
    vector<unordered_map<long long, int>> freq;

    SqrtDecomposition(vector<int>& init) {
        arr = vector<long long>(init.begin(), init.end());
        n = arr.size();
        blockSize = sqrt(n) + 1;
        blockCount = (n + blockSize - 1) / blockSize;
        lazy.assign(blockCount, 0);
        freq.resize(blockCount);
        build();
    }

    void build() {
        for (int b = 0; b < blockCount; b++) rebuildBlock(b);
    }

    void rebuildBlock(int b) {
        freq[b].clear();
        int l = b * blockSize;
        int r = min(n - 1, (b + 1) * blockSize - 1);
        for (int i = l; i <= r; i++) freq[b][arr[i]]++;
    }

    void push(int b) {
        if (lazy[b] == 0) return;
        int l = b * blockSize;
        int r = min(n - 1, (b + 1) * blockSize - 1);
        for (int i = l; i <= r; i++) arr[i] += lazy[b];
        lazy[b] = 0;
    }

    void rangeUpdate(int ql, int qr, int val) {
        int leftBlock = ql / blockSize;
        int rightBlock = qr / blockSize;
        if (leftBlock == rightBlock) {
            push(leftBlock);
            for (int i = ql; i <= qr; i++) arr[i] += val;
            rebuildBlock(leftBlock);
            return;
        }

        // left partial
        push(leftBlock);
        int leftEnd = (leftBlock + 1) * blockSize - 1;
        for (int i = ql; i <= leftEnd; i++) arr[i] += val;
        rebuildBlock(leftBlock);

        // right partial
        push(rightBlock);
        int rightStart = rightBlock * blockSize;
        for (int i = rightStart; i <= qr; i++) arr[i] += val;
        rebuildBlock(rightBlock);

        // full blocks
        for (int b = leftBlock + 1; b < rightBlock; b++) lazy[b] += val;
    }

    int query(long long x) {
        int ans = 0;
        for (int b = 0; b < blockCount; b++) {
            long long target = x - lazy[b];
            auto it = freq[b].find(target);
            if (it != freq[b].end()) ans += it->second;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        SqrtDecomposition* sd = new SqrtDecomposition(nums2);
        vector<int> ans;
        for(auto q : queries) {
            int type = q[0];
            if(type == 1) {
                int x = q[1], y = q[2], val = q[3];
                sd->rangeUpdate(x, y, val);
            } else {
                int tot = q[1];
                int cnt = 0;
                for(auto x : nums1) cnt += sd->query(tot - x);
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};
