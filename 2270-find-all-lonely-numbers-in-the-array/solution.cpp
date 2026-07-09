class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& x : nums) mp[x]++;
        vector<int> ans;
        for(auto& [x, cnt] : mp) {
            if(cnt == 1 && !mp.contains(x - 1) && !mp.contains(x + 1)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
