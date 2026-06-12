class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            bool valid1 = true, valid2 = true;;
            for(int j = 0; j < i; j++) {
                if(nums[j] >= nums[i]) {
                    valid1 = false;
                    break;
                }
            }
            for(int j = i + 1; j < n; j++) {
                if(nums[j] >= nums[i]) {
                    valid2 = false;
                    break;
                }
            }
            if(valid1 || valid2) ans.push_back(nums[i]);
        }
        return ans;
    }
};
