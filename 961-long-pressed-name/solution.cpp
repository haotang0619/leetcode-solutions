class Solution {
public:
    void build(string& s, vector<pair<char, int>>& v) {
        int cnt = 0;
        char prev = '\0';
        for(auto& c : s) {
            if(c != prev) {
                if(cnt > 0) v.push_back({c, cnt});
                cnt = 0;
            }
            prev = c;
            cnt++;
        }
        v.push_back({prev, cnt});
    }
    
    bool isLongPressedName(string name, string typed) {
        vector<pair<char, int>> v1, v2;
        build(name, v1);
        build(typed, v2);
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i].first != v2[i].first) return false;
            if(v1[i].second > v2[i].second) return false;
        }
        return true;
    }
};
