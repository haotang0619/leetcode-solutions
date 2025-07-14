class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(char c = 'a'; c <= 'z'; c++) mp[c] = 0;
        for(char c = 'A'; c <= 'Z'; c++) mp[c] = 0;
        for(auto x : s) mp[x]++;
        int ans = 0;
        for(char c = 'A'; c <= 'z'; c == 'Z' ? c = 'a' : c++) {
            ans += mp[c] - mp[c] % 2;
            if(ans % 2 == 0 && mp[c] % 2) ans++;
        }
        return ans;
    }
};
