class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        vector<int> mp(26, 0);
        for(auto& c : s) mp[c - 'a']++;
        string t;
        for(int i = 0; i < mp[y - 'a']; i++) t += y;
        for(int i = 0; i < 26; i++) {
            if(i == (y - 'a')) continue;
            for(int j = 0; j < mp[i]; j++) t += ('a' + i);
        }
        return t;
    }
};
