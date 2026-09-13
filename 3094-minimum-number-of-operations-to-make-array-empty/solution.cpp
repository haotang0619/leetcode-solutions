class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto& num : nums) mp[num]++;
        int ans = 0;
        for(auto& [_, cnt] : mp) {
            if(cnt % 3 == 0) ans += cnt / 3;
            else if(cnt % 3 == 1) {
                if(cnt == 1) return -1;
                ans += (cnt / 3 - 1) + 2;
            } else {
                ans += cnt / 3 + 1;
            }
        }
        return ans;
    }
};
