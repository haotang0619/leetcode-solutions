class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), now = 0;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = now ^ pref[i], now ^= ans[i];
        return ans;
    }
};
