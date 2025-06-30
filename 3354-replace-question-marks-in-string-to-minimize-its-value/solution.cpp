class Solution {
public:
    string minimizeStringValue(string s) {
        map<char, int> mp, mp2;
        for(char c = 'a'; c <= 'z'; c++) {
            mp[c] = 0;
            mp2[c] = 0;
        }
        for(auto c : s) mp2[c]++;

        vector<char> replaced;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '?') {
                int min_c = 'a', min_cnt = mp['a'] + mp2['a'];
                for(char c = 'b'; c <= 'z'; c++) {
                    if(min_cnt > mp[c] + mp2[c]) {
                        min_cnt = mp[c] + mp2[c];
                        min_c = c;
                    }
                }
                replaced.push_back(min_c);
                mp[min_c]++;
            } else {
                mp[s[i]]++;
                mp2[s[i]]--;
            }
        }
        sort(replaced.begin(), replaced.end());
        for(int i = 0, j = 0; i < s.size(); i++) {
            if(s[i] == '?') s[i] = replaced[j++];
        }
        return s;
    }
};
