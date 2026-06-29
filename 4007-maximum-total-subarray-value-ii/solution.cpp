// Saw all hints and asked GPT for the pq logic
class SparseTable {
public:
    vector<vector<pair<int, int>>> st; // [mn, mx]
    vector<int> lg;

    SparseTable(vector<int>& arr) {
        int n = arr.size();
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        st.assign(n, vector<pair<int, int>>(lg[n] + 1));
        for (int i = 0; i < n; i++) st[i][0] = {arr[i], arr[i]};
        for (int j = 1; j <= lg[n]; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = {
                    min(st[i][j - 1].first, st[i + (1 << (j - 1))][j - 1].first),
                    max(st[i][j - 1].second, st[i + (1 << (j - 1))][j - 1].second),
                };
            }
        }
    }

    int query(int l, int r, int type) {
        int len = r - l + 1;
        int k = lg[len];
        return type == 0 ? min(st[l][k].first, st[r - (1 << k) + 1][k].first) : max(st[l][k].second, st[r - (1 << k) + 1][k].second);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);
        priority_queue<vector<int>> pq; // [diff, i, j]
        for(int i = 0; i <= n - 1; i++) {
            pq.push({st.query(i, n - 1, 1) - st.query(i, n - 1, 0), i, n - 1});
        }
        long long ans = 0;
        while(k--) {
            auto top = pq.top();
            pq.pop();
            int diff = top[0], i = top[1], j = top[2];
            if(j - 1 >= i) pq.push({st.query(i, j - 1, 1) - st.query(i, j - 1, 0), i, j - 1});
            ans += diff;
        }
        return ans;
    }
};
