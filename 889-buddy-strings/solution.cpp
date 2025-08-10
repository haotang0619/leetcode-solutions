class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        vector<int> diff;
        map<char, int> mp;
        bool hasDuplicate = false;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if(mp[s[i]] >= 2) hasDuplicate = true;
            if(s[i] != goal[i]) diff.push_back(i);
            if(diff.size() > 2) return false;
        }
        if(diff.size() == 1) return false;
        if(diff.size() == 0) return hasDuplicate;
        swap(s[diff[0]], s[diff[1]]);
        return s == goal;
    }
};
