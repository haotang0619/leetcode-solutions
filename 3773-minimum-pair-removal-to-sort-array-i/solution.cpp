class Solution {
public:
    bool isValid(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] > nums[i]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(isValid(nums)) return i;
            int minIdx = -1, minSum = INT_MAX;
            for(int j = 0; j < nums.size() - 1; j++) {
                if(nums[j] + nums[j + 1] < minSum) {
                    minIdx = j;
                    minSum = nums[j] + nums[j + 1];
                }
            }
            nums[minIdx] = minSum;
            nums.erase(nums.begin() + minIdx + 1);
        }
        return n - 1;
    }
};
