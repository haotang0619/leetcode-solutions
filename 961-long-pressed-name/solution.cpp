class Solution {
public:
    void count(string &s, vector<pair<char, int>> &v) {
        char prev = '\0';
        int cnt = 0;
        for(auto c : s) {
            if(prev != '\0' && prev != c) {
                v.push_back({prev, cnt});
                cnt = 0;
            }
            cnt++;
            prev = c;
        }
        v.push_back({prev, cnt});
    }

    bool isLongPressedName(string name, string typed) {
        vector<pair<char, int>> v1, v2;
        count(name, v1);
        count(typed, v2);
        if(v1.size() != v2.size()) return false;
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i].first != v2[i].first || v1[i].second > v2[i].second)
                return false;
        }
        return true;
    }
};
