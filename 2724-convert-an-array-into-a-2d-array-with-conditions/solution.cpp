class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for(auto x : nums) mp[x]++;
        for(auto [num, cnt] : mp) {
            for(int i = 0; i < cnt; i++) {
                if(ans.size() <= i) ans.push_back({num});
                else ans[i].push_back(num);
            }
        }
        return ans;
    }
};
