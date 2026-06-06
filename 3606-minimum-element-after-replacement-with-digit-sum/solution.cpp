class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto x : nums) {
            int now = 0;
            while(x > 0) {
                now += x % 10;
                x /= 10;
            }
            ans = min(ans, now);
        }
        return ans;
    }
};
