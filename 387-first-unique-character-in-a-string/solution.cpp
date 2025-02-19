class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        vector<int> firstPos(26, -1);
        
        for(int i = 0; i < s.length(); i++) {
            if(firstPos[s[i] - 'a'] == -1) firstPos[s[i] - 'a'] = i;
            freq[s[i] - 'a']++;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 1) ans = min(ans, firstPos[i]);
        }
        
        return (ans == INT_MAX ? -1 : ans);
    }
};
