class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        for(auto x : answers) {
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
        }
        int ans = 0;
        for(auto x : mp) {
            int size = x.first + 1;
            ans += size * (x.second / size + (x.second % size == 0 ? 0 : 1));
        }
        return ans;
    }
};
