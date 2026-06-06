class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        for(int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int r = stoi(s);
            if(!mp.contains(r)) continue;
            int idx = upper_bound(mp[r].begin(), mp[r].end(), i) - mp[r].begin();
            if(idx != mp[r].size()) ans = min(ans, mp[r][idx] - i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
