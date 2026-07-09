class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, unordered_set<int>> mp;
        unordered_set<int> ends;
        for(auto& p : adjacentPairs) {
            mp[p[0]].insert(p[1]);
            mp[p[1]].insert(p[0]);
            if(mp[p[0]].size() == 1) ends.insert(p[0]);
            else ends.erase(p[0]);
            if(mp[p[1]].size() == 1) ends.insert(p[1]);
            else ends.erase(p[1]);
        }
        int now = *ends.begin(), last = *(next(ends.begin()));
        vector<int> ans = {now};
        while(now != last) {
            for(auto& x : mp[now]) {
                ans.push_back(x);
                mp[x].erase(now);
                now = x;
            }
        }
        return ans;
    }
};
