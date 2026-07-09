class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        vector<pair<char, int>> v1, v2;
        for(int i = 0; i < n; i++) {
            if(start[i] != 'X') v1.push_back({start[i], i});
            if(result[i] != 'X') v2.push_back({result[i], i});
        }
        if(v1.size() != v2.size()) return false;
        int m = v1.size();
        for(int i = 0; i < m; i++) {
            auto& [c1, i1] = v1[i];
            auto& [c2, i2] = v2[i];
            if(c1 != c2) return false;
            if(c1 == 'R' && i1 > i2) return false;
            if(c1 == 'L' && i1 < i2) return false;
        }
        return true;
    }
};
