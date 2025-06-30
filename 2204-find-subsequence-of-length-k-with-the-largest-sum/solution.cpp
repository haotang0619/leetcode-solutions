class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> pos;
        for(int i = 0; i < nums.size(); i++) pos.push_back(i);
        sort(pos.begin(), pos.end(), [&nums](int a, int b){
            return nums[a] > nums[b];
        });
        sort(pos.begin(), pos.begin() + k);
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(nums[pos[i]]);
        return ans;
    }
};
