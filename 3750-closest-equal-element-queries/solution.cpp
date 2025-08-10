class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        vector<int> ans;
        for(auto i : queries) {
            int x = nums[i];
            int size = mp[x].size();
            if(size == 1) ans.push_back(-1);
            else {
                int idx = lower_bound(mp[x].begin(), mp[x].end(), i) - mp[x].begin();
                int i1 = mp[x][(idx + 1) % size];
                int i2 = mp[x][(idx - 1 + size) % size];
                int dist1 = i1 > i ? i1 - i : (i1 + n - i);
                int dist2 = i > i2 ? i - i2 : (i + n - i2);
                ans.push_back(min(dist1, dist2));
            }
        }
        return ans;
    }
};
