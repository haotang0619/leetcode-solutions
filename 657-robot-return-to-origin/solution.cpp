class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> mp;
        for(auto m : moves) mp[m]++;
        return mp['U'] == mp['D'] && mp['L'] == mp['R'];
    }
};
