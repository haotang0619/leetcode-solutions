class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), ans = n + 1, j = n - 1, sum1 = 0, sum2 = 0;
        while(j >= 0) sum2 += nums[j--];
        for(int i = 0; i < n; i++) {
            while((sum1 + sum2 > x || j + 1 < i) && j < n - 1) sum2 -= nums[++j];
            if(sum1 + sum2 == x) ans = min(ans, i + n - j - 1);
            sum1 += nums[i];
            if(sum1 > x) break;
        }
        return ans == n + 1 ? -1 : ans;
    }
};
