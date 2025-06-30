class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) continue;
            int curr = nums[i], cnt = 1;
            while(curr <= 46340) {
                auto x = lower_bound(nums.begin() + i + 1, nums.end(), curr * curr);
                if(x == nums.end() || nums[x - nums.begin()] != curr * curr) break;
                else cnt++, curr *= curr;
            }
            if(cnt >= 2) ans = max(ans, cnt);
        }
        return ans;
    }
};
