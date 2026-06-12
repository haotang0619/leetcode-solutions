// Searched for Sparse Table
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
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;
        int k = lg[len];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        vector<SparseTable*> v;
        for(int i = 0; i < m; i++) v.push_back(new SparseTable(matrix[i]));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int num = matrix[i][j];
                if(num == 0) continue;
                bool valid = true;
                for(int k = max(0, i - num); k <= min(m - 1, i + num); k++) {
                    int l = max(0, j - num), r = min(n - 1, j + num);
                    if(k == i - num || k == i + num) {
                        if(l == j - num) l++;
                        if(r == j + num) r--;
                    }
                    int maxNow = v[k]->query(l, r);
                    if(maxNow > num) {
                        valid = false;
                        break;
                    }
                }
                if(valid) ans++;
            }
        }
        return ans;
    }
};
