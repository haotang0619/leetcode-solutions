class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++) for(int j = i + 1; j < size; j++) for(int k = j + 1; k < size; k++) ans = max(ans, (nums[i] - nums[j]) * (long long)nums[k]);
        return ans;
    }
};
