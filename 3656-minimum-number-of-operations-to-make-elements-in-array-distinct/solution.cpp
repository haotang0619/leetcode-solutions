class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        for(auto x : nums) mp[x]++;
        while(nums.size() > 0) {
            bool flag = true;
            for(auto [num, cnt] : mp) {
                if(cnt >= 2) {
                    flag = false;
                    break;
                }
            }
            if(flag) return ans;
            for(int i = 0; i < 3; i++) {
                if(nums.size() > 0) {
                    mp[nums[0]]--;
                    nums.erase(nums.begin());
                }
            }
            ans++;
        }
        return ans;
    }
};
