class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<int, int> mp;
        for(auto x : word) {
            if(x >= 'a' && x <= 'z') mp[x - 'a'] |= 1;
            else mp[x - 'A'] |= 2;
        }
        int ans = 0;
        for(auto p : mp) ans += p.second == 3 ? 1 : 0;
        return ans;
    }
};
