class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st;
        for(auto x : nums) st.insert(x);
        int size = st.size();
        map<int, int> mp;
        int l = 0, ans = 0;
        for(int r = 0; r < nums.size(); r++) {
            if(mp.find(nums[r]) == mp.end()) mp[nums[r]] = 0;
            mp[nums[r]]++;
            while(l <= r && mp.size() == st.size()) {
                ans += nums.size() - r;
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
        }
        return ans;
    }
};
