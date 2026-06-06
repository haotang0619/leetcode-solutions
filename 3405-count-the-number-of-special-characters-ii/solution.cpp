class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<int, int> mp;
        for(auto x : word) {
            if(mp[x - 'a'] == -1) continue;
            if(x >= 'a' && x <= 'z') {
                if(mp[x - 'a'] == 3) mp[x - 'a'] = -1;
                else mp[x - 'a'] |= 1;
            } else if(mp[x - 'A'] == 1) {
                mp[x - 'A'] |= 2;
            } else if(mp[x - 'A'] == 0) {
                mp[x - 'A'] = -1;
            }
        }
        int ans = 0;
        for(auto p : mp) ans += p.second == 3 ? 1 : 0;
        return ans;
    }
};
