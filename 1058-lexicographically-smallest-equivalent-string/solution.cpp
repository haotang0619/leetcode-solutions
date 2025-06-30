class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<char>> v;
        for(char c = 'a'; c <= 'z'; c++) v.push_back(set<char>{c});
        for(int i = 0; i < s1.size(); i++) {
            int idx1 = -1, idx2 = 1;
            for(int idx = 0; idx < v.size(); idx++) {
                if(v[idx].find(s1[i]) != v[idx].end()) idx1 = idx;
                if(v[idx].find(s2[i]) != v[idx].end()) idx2 = idx;
            }
            if(idx1 == idx2) continue;
            v[idx1].insert(v[idx2].begin(), v[idx2].end());
            v.erase(v.begin() + idx2);
        }
        for(int i = 0; i < baseStr.size(); i++) {
            for(auto x : v) {
                if(x.find(baseStr[i]) != x.end()){
                    baseStr[i] = *x.begin();
                    break;
                }
            }
        }
        return baseStr;
    }
};
