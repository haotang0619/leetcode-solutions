class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = nums[0], now = nums[0];
        set<int> st = {nums[0]};
        for(int l = 0, r = 1; r < nums.size(); r++) {
            while(st.count(nums[r])) {
                st.erase(nums[l]);
                now -= nums[l];
                l++;
            }
            now += nums[r];
            st.insert(nums[r]);
            ans = max(ans, now);
        }
        return ans;
    }
};
