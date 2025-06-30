class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, vector<int>> mp;
        for(auto x : stones) mp[x] = vector<int>(2001, 0);
        mp[0][1] = 1;
        for(auto x : stones) {
            if(x == 0) continue;
            for(int i = 1; i <= 2000; i++) {
                for(int j = i - 1; j <= i + 1; j++) {
                    if(j <= 0 || j > 2000) continue;
                    int last = x - j;
                    if(last >= 0 && mp.find(last) != mp.end() && mp[last][j] == 1) mp[x][i] = 1;
                }
            }
        }
        for(auto x : mp[stones.back()]) {
            if(x == 1) return true;
        }
        return false;
    }
};
