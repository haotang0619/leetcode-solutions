class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnts(26, 0);
        for(auto& c : chars) cnts[c - 'a']++;
        int ans = 0;
        for(auto& w : words) {
            vector<int> tmp(26, 0);
            int add = w.size();
            for(auto& c : w) {
                tmp[c - 'a']++;
                if(tmp[c - 'a'] > cnts[c - 'a']) {
                    add = 0; break;
                }
            }
            ans += add;
        }
        return ans;
    }
};
