class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tails;
        for(auto& num : nums) {
            int idx = lower_bound(tails.begin(), tails.end(), num) - tails.begin();
            if(idx >= tails.size()) tails.push_back(num);
            else tails[idx] = num;
        }
        return tails.size();
    }
};
