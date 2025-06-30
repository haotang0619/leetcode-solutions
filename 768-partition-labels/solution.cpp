class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = {i, i};
            mp[s[i]][1] = i;
        }
        vector<vector<int>> v;
        for(auto x : mp) v.push_back(x.second);
        sort(v.begin(), v.end());
        vector<int> ans;
        int left = v[0][0], right = v[0][1];
        for(auto x : v) {
            if(right < x[0]) {
                ans.push_back(right - left + 1);
                left = x[0];
            }
            right = max(right, x[1]);
        }
        ans.push_back(right - left + 1);
        return ans;
    }
};
