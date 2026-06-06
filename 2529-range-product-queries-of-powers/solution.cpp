class Solution {
public:
    int mod = 1e9 + 7;
    int maxP = (1 + 29) * 29 / 2;
    vector<int> powOf2 = vector<int>(maxP, 1);
    
    void init() {
        for(int i = 1; i < maxP; i++) powOf2[i] = (powOf2[i - 1] * 2) % mod;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        init();
        vector<int> vp;
        for(int p = 0; n > 0; n >>= 1, p++) {
            if(n & 1 == 1) {
                int prev = vp.size() >= 1 ? vp.back() : 0;
                vp.push_back(p + prev);
            }
        }
        vector<int> ans;
        for(auto q : queries) {
            int l = q[0], r = q[1];
            int p = vp[r] - (l > 0 ? vp[l - 1] : 0);
            ans.push_back(powOf2[p]);
        }
        return ans;
    }
};
