// Saw all hints and asked AI
class SparseTable {
public:
    vector<vector<int>> st;
    vector<int> lg;

    SparseTable(vector<int>& arr) {
        int n = arr.size();
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        st.assign(n, vector<int>(lg[n] + 1));
        for (int i = 0; i < n; i++) st[i][0] = arr[i];
        for (int j = 1; j <= lg[n]; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];
        return gcd(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
        SparseTable st(nums);
        int n = nums.size(), l = 0, r = n;

        auto check = [&](int m) {
            if(m == n) return true;
            int cnt = 0;
            for(int i = 0; i < n - m; i++) {
                int val = st.query(i, i + m);
                if(val > 1) cnt++, i = i + m;
                if(cnt > maxC) return false;
            }
            return true;
        };

        while(l < r) {
            int m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
