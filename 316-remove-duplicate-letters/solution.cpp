class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            if(!mp.count(s[i])) mp[s[i]] = {};
            mp[s[i]].push_back(i);
        }
        int minIdx = -1;
        string ans;
        while(!mp.empty()) {
            for(auto [c1, v1] : mp) {
                int i1;
                for(int i = 0; i < v1.size(); i++) {
                    if(v1[i] > minIdx) {
                        i1 = v1[i];
                        break;
                    }
                }
                bool flag = true;
                for(auto [c2, v2] : mp) {
                    if(c1 == c2) continue;
                    if(i1 > v2.back()) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans += c1;
                    minIdx = i1;
                    mp.erase(c1);
                    break;
                }
            }
        }
        return ans;
    }
};
