class Solution {
public:
    vector<pair<int, char>> getVector(string s) {
        vector<pair<int, char>> v;
        char prev = s[0];
        int cnt = 1;
        for(int i = 1; i < s.length(); i++) {
            if(prev == s[i]) cnt++;
            else {
                v.push_back({cnt, prev});
                cnt = 1;
            }
            prev = s[i];
        }
        v.push_back({cnt, prev});    
        return v;
    }

    int expressiveWords(string s, vector<string>& words) {
        vector<pair<int, char>> v = getVector(s);

        int ans = 0;
        for(auto w : words) {
            vector<pair<int, char>> v1 = getVector(w);
            if(v.size() == v1.size()) {
                bool flag = true;
                for(int i = 0; i < v.size(); i++) {
                    if(v[i].second != v1[i].second || v[i].first < 3 && v[i].first != v1[i].first || v[i].first >= 3 && v[i].first < v1[i].first) {
                        flag = false;
                        break;
                    }
                }
                ans += flag ? 1 : 0;
            }
        }
        return ans;
    }
};
