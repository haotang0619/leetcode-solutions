// Saw discussions and asked GPT
class Solution {
public:
    void findAns(vector<int> &ans, int n, int l, int r) {
        if(n == 1) {
            ans[l] = 1;
            return;
        }
        if(n % 2 == 0) {
            findAns(ans, n / 2, l, l + n / 2 - 1); // odd
            for(int i = l; i <= l + n / 2 - 1; i++) ans[i] = ans[i] * 2 - 1;
            findAns(ans, n / 2, l + n / 2, r); // even
            for(int i = l + n / 2; i <= r; i++) ans[i] = ans[i] * 2;
        } else {
            findAns(ans, n / 2 + 1, l, l + n / 2); // odd
            for(int i = l; i <= l + n / 2; i++) ans[i] = ans[i] * 2 - 1;
            findAns(ans, n / 2, l + n / 2 + 1, r); // even
            for(int i = l + n / 2 + 1; i <= r; i++) ans[i] = ans[i] * 2;
        }
    }

    vector<int> beautifulArray(int n) {
        vector<int> ans(n);
        findAns(ans, n, 0, n - 1);
        return ans;
    }
};
