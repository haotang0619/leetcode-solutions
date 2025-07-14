class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> banned(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for(auto x : message) {
            cnt += banned.count(x);
            if(cnt >= 2) return true;
        }
        return false;
    }
};
