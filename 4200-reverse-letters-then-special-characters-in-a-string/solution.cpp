class Solution {
public:
    string reverseByType(string s) {
        vector<pair<char, int>> v1, v2;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') v1.push_back({s[i], i});
            else v2.push_back({s[i], i});
        }
        string s1 = s;
        for(int i = 0; i < v1.size(); i++) {
            int j = v1.size() - 1 - i;
            s1[v1[i].second] = v1[j].first;
        }
        for(int i = 0; i < v2.size(); i++) {
            int j = v2.size() - 1 - i;
            s1[v2[i].second] = v2[j].first;
        }
        return s1;
    }
};
