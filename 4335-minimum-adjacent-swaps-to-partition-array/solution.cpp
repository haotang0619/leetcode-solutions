class Solution {
public:
    int mod = 1e9 + 7;
    void mergeSort(vector<int>& v, int& ans, int& a, int& b, int l, int r) {
        if(l == r) return;
        int m = l + (r - l) / 2;
        mergeSort(v, ans, a, b, l, m);
        mergeSort(v, ans, a, b, m + 1, r);
        vector<int> tmp(r - l + 1);
        int i = l, j = m + 1, k = 0, cnt1 = 0, cnt2 = 0;
        while(i <= m && j <= r) {
            if(v[i] <= v[j]) {
                if(v[i] > b) ans = (ans + cnt2) % mod;
                else if(v[i] >= a) ans = (ans + cnt1) % mod;
                tmp[k++] = v[i++];
            } else {
                if(v[j] < a) cnt1++;
                if(v[j] <= b) cnt2++;
                tmp[k++] = v[j++];
            }
        }
        while(i <= m) {
            if(v[i] > b) ans = (ans + cnt2) % mod;
            else if(v[i] >= a) ans = (ans + cnt1) % mod;
            tmp[k++] = v[i++];
        }
        while(j <= r) tmp[k++] = v[j++];
        for(int i = l; i <= r; i++) v[i] = tmp[i - l];
    }
    
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int ans = 0, n = nums.size();
        mergeSort(nums, ans, a, b, 0, n - 1);
        return ans;
    }
};
