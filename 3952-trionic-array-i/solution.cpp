class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for(int p = 1; p < n - 2; p++) {
            for(int q = p + 1; q < n - 1; q++) {
                bool flag = true;
                for(int i = 1; i < n; i++) {
                    if(i <= p || i > q) {
                        if(nums[i] <= nums[i - 1]) {
                            flag = false;
                            break;
                        }
                    }
                    else if(nums[i] >= nums[i - 1]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }
        }
        return false;
    }
};
