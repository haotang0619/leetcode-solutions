class Solution {
public:
    vector<int> grayCode(int n) {
        int mx = 1 << n, sz = 2;
        vector<int> ans(mx, 0);
        ans[1] = 1;
        while(sz < mx) {
            for(int i = sz; i < sz * 2; i++) {
                int pos = i - sz + 1;
                ans[i] = sz + ans[sz - pos];
            }
            sz <<= 1;
        }
        return ans;
    }
};
