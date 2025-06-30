class Solution {
public:
    // Checked Solution from 3356 => Difference Array
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> dec(nums.size() + 1, 0);
        for(auto &x : queries) ++dec[x[0]], --dec[x[1] + 1];
        for(int i = 0, sum = 0; i < nums.size(); i++) {
            sum += dec[i];
            if(nums[i] > sum) return false;
        }
        return true;
    }
};
