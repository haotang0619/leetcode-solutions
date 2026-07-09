// Saw a solution
class Solution {
public:
    void dfs(vector<string>& ans, unordered_map<string, multiset<string>>& mp, string now) {
        while(!mp[now].empty()) {
            string next = *mp[now].begin();
            mp[now].erase(mp[now].find(next));
            dfs(ans, mp, next);
        }
        ans.push_back(now);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mp;
        for(auto& t : tickets) mp[t[0]].insert(t[1]);
        vector<string> ans;
        dfs(ans, mp, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
