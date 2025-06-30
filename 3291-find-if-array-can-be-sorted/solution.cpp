class Solution {
public:
    int getOneCnt(int x) {
        int cnt = 0;
        while(x > 0) {
            cnt += (x & 1);
            x >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < nums.size() - i; j++) {
                if(nums[j] > nums[j + 1]) {
                    if(getOneCnt(nums[j]) != getOneCnt(nums[j + 1])) {
                        return false;
                    }
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return true;
    }
};
