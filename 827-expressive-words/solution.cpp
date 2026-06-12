class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> v;
        char prev = '\0', cnt = 0;
        for(auto c : s) {
            if(c != prev) {
                if(prev != '\0') v.push_back({prev, cnt});
                cnt = 0;
            }
            prev = c;
            cnt++;
        }
        v.push_back({prev, cnt});
        int ans = 0;
        for(auto w : words) {
            prev = '\0', cnt = 0;
            int idx = 0;
            bool valid = true;
            for(auto c : w) {
                if(c != prev) {
                    if(prev != '\0') {
                        if(idx >= v.size() || prev != v[idx].first || cnt > v[idx].second) {
                            valid = false;
                            break;
                        }
                        if(cnt != v[idx].second && v[idx].second < 3) {
                            valid = false;
                            break;
                        }
                        idx++;
                    }
                    cnt = 0;
                }
                prev = c;
                cnt++;
            }
            if(idx < v.size()) {
                if(prev != v[idx].first || cnt > v[idx].second) {
                    valid = false;
                }
                if(cnt != v[idx].second && v[idx].second < 3) {
                    valid = false;
                }
                idx++;
            } else valid = false;
            if(idx != v.size()) valid = false;
            if(valid) ans++;
        }
        return ans;
    }
};
