class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        int ans = INT_MAX;
        for(auto &x : mp) {
            int l = x.second.size();
            for(int i = 0; i + 2 < l; i++) {
                ans = min(ans, (x.second[i + 2] - x.second[i]) * 2);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
