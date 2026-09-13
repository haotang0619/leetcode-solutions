class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int all = INT_MAX;
        for(auto& num : nums) all &= num;
        int ans = 0, now = INT_MAX;
        if(all > 0) return 1;
        for(auto& num : nums) {
            now &= num;
            if(now == all) ans++, now = INT_MAX;
        }
        return ans;
    }
};
