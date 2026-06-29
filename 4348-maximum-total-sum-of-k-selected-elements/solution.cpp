class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            int n = nums[i];
            if(mul <= 1) ans += n;
            else ans += max((long long)n * mul, (long long)n);
            mul--;
        }
        return ans;
    }
};
