class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCnt = 0;
        for(auto &c : word) {
            if(c >= 'A' && c <= 'Z') capCnt++;
        }
        return capCnt == 0 || capCnt == word.size() || capCnt == 1 && word[0] >= 'A' && word[0] <= 'Z';
    }
};
