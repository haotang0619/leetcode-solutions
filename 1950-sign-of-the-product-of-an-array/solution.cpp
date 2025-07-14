class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto x : nums) {
            ans *= (x > 0 ? 1 : (x < 0 ? -1 : 0));
        }
        return ans;
    }
};
