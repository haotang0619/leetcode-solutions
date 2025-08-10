class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(auto x : deck) mp[x]++;
        int size = -1;
        for(auto [x, cnt] : mp) {
            if(size == -1) size = cnt;
            else size = gcd(size, cnt);
        }
        return size > 1;
    }
};
