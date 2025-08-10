class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                mp[word[j]]++;
            }
            int nowCnt = -1;
            bool isValid = true;
            for(auto [c, cnt] : mp) {
                if(nowCnt == -1) nowCnt = cnt;
                else if(nowCnt != cnt) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) return true;
        }
        return false;
    }
};
