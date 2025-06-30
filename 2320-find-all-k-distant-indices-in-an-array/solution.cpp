class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i - k; j <= i + k; j++) {
                if(j < 0 || j >= nums.size()) continue;
                if(nums[j] == key) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
