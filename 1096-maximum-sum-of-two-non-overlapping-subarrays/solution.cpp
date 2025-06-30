class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> prefix_sum(nums.size(), nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        int ans = -1;
        for(int i = firstLen - 1; i < nums.size(); i++) {
            int last = i - firstLen >= 0 ? prefix_sum[i - firstLen] : 0;
            int first_sum = prefix_sum[i] - last;
            int second_sum = -1;
            for(int j = secondLen - 1; j <= i - firstLen; j++) {
                int l = j - secondLen >= 0 ? prefix_sum[j - secondLen] : 0;
                second_sum = max(second_sum, prefix_sum[j] - l);
            }
            for(int j = i + secondLen; j < nums.size(); j++) {
                int l = j - secondLen >= 0 ? prefix_sum[j - secondLen] : 0;
                second_sum = max(second_sum, prefix_sum[j] - l);
            }
            ans = max(ans, first_sum + second_sum);
        }
        return ans;
    }
};
