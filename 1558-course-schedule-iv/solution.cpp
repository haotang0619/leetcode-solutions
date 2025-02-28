class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto x : prerequisites) {
            mp[x[0]].insert(x[1]);
            mp[x[0]].insert(mp[x[1]].begin(), mp[x[1]].end());
            for(auto &m : mp) {
                if(m.second.find(x[0]) != m.second.end()) {
                    m.second.insert(mp[x[0]].begin(), mp[x[0]].end());
                }
            }
        }

        vector<bool> ans;
        for(auto x : queries) ans.push_back(mp[x[0]].find(x[1]) != mp[x[0]].end());
        return ans;
    }
};
