class Solution {
public:
    int mod = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        vector<int> pow2(22, 1);
        for(int i = 1; i <= 21; i++) pow2[i] = pow2[i - 1] * 2;
        vector<int> mp(pow2[21] + 1, 0);
        int ans = 0;
        for(auto& x : deliciousness) {
            for(int i = 0; i <= 21; i++) {
                if(pow2[i] < x) continue;
                ans = (ans + mp[pow2[i] - x]) % mod;
            }
            mp[x]++;
        }
        return ans;
    }
};
