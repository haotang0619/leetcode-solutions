class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mp;
        string ans = "";
        int maxCnt = 0;
        for(auto &res : responses) {
            unordered_set<string> seen;
            for(auto &s : res) {
                if(seen.count(s) > 0) continue;
                mp[s]++;
                if(maxCnt < mp[s]) {
                    maxCnt = mp[s];
                    ans = s;
                }
                if(maxCnt == mp[s]) ans = min(ans, s);
                seen.insert(s);
            }
        }
        return ans;
    }
};
