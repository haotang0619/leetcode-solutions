class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int l = 0, ans = 0, neg_cnt = 0;
        nums.push_back(0);
        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] < 0) neg_cnt++;
            if(nums[r] != 0 && neg_cnt % 2 == 0) {
                ans = max(ans, r - l + 1);
            }
            if(nums[r] == 0) {
                while(neg_cnt % 2 == 1) {
                    if(nums[l] < 0) neg_cnt--;
                    l++;
                }
                ans = max(ans, r - l);
                neg_cnt = 0;
                l = r + 1;
            }
        }
        return ans;
    }
};
