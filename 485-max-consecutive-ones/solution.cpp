class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, now = 0;
        for(auto x : nums) {
            if(x == 1) now++;
            else {
                ans = max(ans, now);
                now = 0;
            }
        }
        ans = max(ans, now);
        return ans;
    }
};
