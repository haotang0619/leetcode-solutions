class Solution {
public:
    bool check(vector<string>& v, unordered_map<string, vector<char>>& mp, int lv) {
        if(lv == v.size()) return true;
        int idx = v[lv].size();
        int nextLv = idx + 1 == v.size() - lv ? lv + 1 : lv;
        string prev = {v[lv - 1][idx], v[lv - 1][idx + 1]};
        bool valid = false;
        for(auto& c : mp[prev]) {
            v[lv] += c;
            valid = valid || check(v, mp, nextLv);
            v[lv].pop_back();
        }
        return valid;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        for(auto& s : allowed) mp[s.substr(0, 2)].push_back(s[2]);
        int n = bottom.size();
        vector<string> v(n);
        v[0] = bottom;
        return check(v, mp, 1);
    }
};
