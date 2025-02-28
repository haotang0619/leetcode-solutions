class Solution {
public:
    int mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        vector<int> dp1 = {0, 0};
        vector<int> dp2 = {0, 0};
        for(auto x : arr) {
            int isOdd = x % 2 == 1;
            if(isOdd) {
                dp1 = {(dp1[0] + dp2[1] + 1) % mod, (dp1[1] + dp2[0]) % mod};
                dp2 = {(dp2[1] + 1) % mod, dp2[0]};
            } else {
                dp1 = {(dp1[0] + dp2[0]) % mod, (dp1[1] + dp2[1] + 1) % mod};
                dp2 = {dp2[0], (dp2[1] + 1) % mod};
            }
        }
        return dp1[0];
    }
};
