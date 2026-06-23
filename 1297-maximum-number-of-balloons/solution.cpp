class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int, int> mp;
        for(auto &c : text) mp[c]++;
        return min(min(mp['a'], mp['b']), min(min(mp['l'] / 2, mp['o'] / 2), mp['n']));
    }
};
