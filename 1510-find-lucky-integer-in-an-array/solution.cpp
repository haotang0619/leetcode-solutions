class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for(auto x : arr) mp[x]++;
        int ans = -1;
        for (auto [num, cnt] : mp) {
            if(num == cnt) ans = num;
        }
        return ans;
    }
};
