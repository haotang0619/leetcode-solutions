class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) result ^= nums[i];
        vector<int> ans;
        for(int i = nums.size() - 1; i >= 0; i--) {
            int part = (result & (int)(pow(2, maximumBit) - 1));
            ans.push_back(pow(2, maximumBit) - 1 - part);
            result ^= nums[i];
        }
        return ans;
    }
};
