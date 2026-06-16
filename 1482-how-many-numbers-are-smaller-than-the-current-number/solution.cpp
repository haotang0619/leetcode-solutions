class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {        
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int now = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(nums[j] < nums[i]) now++;
            }
            ans[i] = now;
        }
        return ans;
    }
};
