class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        for(auto& m : matches) {
            mp[m[1]]++;
            if(!mp.contains(m[0])) mp[m[0]] = 0;
        }
        vector<vector<int>> ans(2);
        for(auto& [idx, cnt] : mp) {
            if(cnt == 0) ans[0].push_back(idx);
            else if(cnt == 1) ans[1].push_back(idx);
        }
        return ans;
    }
};
