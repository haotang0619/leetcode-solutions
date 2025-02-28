class Solution {
public:
    int combOf2(int num) {
        return num * (num - 1) / 2;
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0;
        for(auto &x : mp) {
            if(x.second >= 2) {
                ans += combOf2(x.second) * 8;
            }
        }
        return ans;
    }
};
