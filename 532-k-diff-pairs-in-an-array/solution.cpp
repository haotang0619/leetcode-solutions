class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto x : nums) {
            if(mp.find(x) == mp.end()) mp[x] = 0;
            mp[x]++;
        }
        int ans = 0;
        for(auto p : mp) {
            auto [x, cnt] = p;
            if(k == 0) {
                if(cnt >= 2) ans++;
            } else if(mp.find(x + k) != mp.end()) ans++;
        }
        return ans;
    }
};
