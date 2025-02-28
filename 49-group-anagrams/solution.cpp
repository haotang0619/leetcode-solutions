class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted_strs;
        for(string x : strs) {
            string s = x;
            sort(s.begin(), s.end());
            sorted_strs.push_back(s);
        }
        
        map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++) {
            mp[sorted_strs[i]].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
