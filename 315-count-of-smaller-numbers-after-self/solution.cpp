class Solution {
public:
    void mergeSort(vector<int>& ans, vector<pair<int, int>>& v, int l, int r) {
        if(l == r) return;
        int m = l + (r - l) / 2;
        mergeSort(ans, v, l, m);
        mergeSort(ans, v, m + 1, r);
        vector<pair<int, int>> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while(i <= m && j <= r) {
            if(v[i].first <= v[j].first) {
                ans[v[i].second] += j - (m + 1);
                tmp[k++] = v[i++];
            } else tmp[k++] = v[j++];
        }
        while(i <= m) {
            ans[v[i].second] += j - (m + 1);
            tmp[k++] = v[i++];
        }
        while(j <= r) tmp[k++] = v[j++];
        for(int i = l; i <= r; i++) v[i] = tmp[i - l];
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) v[i] = {nums[i], i};
        mergeSort(ans, v, 0, n - 1);
        return ans;
    }
};
