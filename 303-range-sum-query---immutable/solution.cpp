class NumArray {
public:
    vector<int> pSum;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pSum.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];    
    }
    
    int sumRange(int left, int right) {
        return pSum[right + 1] - pSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
