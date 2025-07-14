class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int, int> mp;
        vector<int> ans;
        for(int i = -50; i <= 50; i++) mp[i] = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(i + 1 >= k) {
                int now = 0;
                for(int j = -50; j <= 0; j++) {
                    now += mp[j];
                    if(now >= x || j >= 0) {
                        ans.push_back(j);
                        break;
                    }
                }
                mp[nums[i - k + 1]]--;
            }
        }
        return ans;
    }
};
