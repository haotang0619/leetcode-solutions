class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 1;
        for(int i = 0; i < 30; i++) {
            int cnt = 0;
            for(auto x : candidates) {
                x >>= i;
                cnt += (x & 1);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
