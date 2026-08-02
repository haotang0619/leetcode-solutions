class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<int, int> mp;
        for(auto& c : s) mp[c]++;
        char end = '\0';
        string ans;
        for(char c = 'a'; c <= 'z'; c++) {
             for(int i = 0; i < mp[c] / 2; i++) ans += c;
            if(mp[c] % 2 == 1) end = c;
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if(end != '\0') return ans + end + rev;
        return ans + rev;
    }
};
