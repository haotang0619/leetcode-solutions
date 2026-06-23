class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<tuple<int, string, string>> valid;
        int k = indices.size();
        for(int i = 0; i < k; i++) {
            int size = sources[i].size();
            if(i + size > s.size()) continue;
            if(s.substr(indices[i], size) == sources[i]) {
                valid.push_back({indices[i], sources[i], targets[i]});
            }
        }
        sort(valid.begin(), valid.end());
        int idx = 0;
        string ans;
        for(auto [i, src, tar] : valid) {
            while(idx < i) ans += s[idx++];
            ans += tar;
            idx += src.size();
        }
        while(idx < s.size()) ans += s[idx++];
        return ans;
    }
};
