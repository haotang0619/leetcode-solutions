class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans = {0, 0};
        int idx = 0;
        while(n > 0) {
            if(n & 1) ans[idx]++;
            n >>= 1, idx = 1 - idx;
        }
        return ans;
    }
};
