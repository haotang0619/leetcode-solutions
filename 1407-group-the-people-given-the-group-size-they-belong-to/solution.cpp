class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++) mp[groupSizes[i]].push_back(i);
        vector<vector<int>> ans;
        for(auto& [cnt, v] : mp) {
            ans.push_back({});
            for(auto& x : v) {
                if(ans.back().size() == cnt) ans.push_back({});
                ans.back().push_back(x);
            }
        }
        return ans;
    }
};
