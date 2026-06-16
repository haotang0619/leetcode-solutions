class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<vector<int>> v(26, vector<int>({}));
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if(v[idx].size() == 0) cnt++;
            v[idx].push_back(i);
        }
        string ans;
        int now = 0;
        while(ans.size() < cnt) {
            for(int i = 0; i < 26; i++) {
                if(v[i].size() == 0) continue;
                bool valid = true;
                int idx = 0; 
                while(v[i][idx] < now) idx++;
                for(int j = 0; j < 26; j++) {
                    if(j == i || v[j].size() == 0) continue;
                    int last = v[j][v[j].size() - 1];
                    if(last < v[i][idx]) {
                        valid = false;
                        break;
                    }
                }
                if(valid) {
                    ans += ('a' + i);
                    now = v[i][idx];
                    v[i] = {};
                    break;
                }
            }
        }
        return ans;
    }
};
