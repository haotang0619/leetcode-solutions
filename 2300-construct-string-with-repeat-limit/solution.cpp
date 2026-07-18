class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> mp(26, 0);
        for(auto& c : s) mp[c - 'a']++;
        string ans;
        int cnt = 0;
        while(true) {
            int size = ans.size();
            for(char c = 'z'; c >= 'a'; c--) {
                if(mp[c - 'a'] == 0) continue;
                bool sameBack = ans.size() > 0 && ans.back() == c;
                if(sameBack && cnt == repeatLimit) continue;
                ans += c;
                mp[c - 'a']--;
                if(sameBack) cnt++;
                else cnt = 1;
                break;
            }
            if(size == ans.size()) break;
        }
        return ans;
    }
};
