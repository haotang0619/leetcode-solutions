class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;
        int prev = -1;
        for(auto& num : nums) {
            if(num != prev) mp[num]++;
            prev = num;
        }
        int ans = 0;
        for(auto& [_, cnt] : mp) {
            if(cnt == 1) ans++;
        }
        return ans;
    }
};
