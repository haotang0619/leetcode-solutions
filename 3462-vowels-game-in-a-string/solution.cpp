class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    bool doesAliceWin(string s) {
        for(auto& c : s) {
            if(vowels.contains(c)) return true;
        }
        return false;
    }
};
