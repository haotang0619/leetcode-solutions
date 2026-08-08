class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            int len = n - i - 1;
            sum -= nums[i];
            if((double)nums[i] > (sum / len)) ans++;
        }
        return ans;
    }
};
