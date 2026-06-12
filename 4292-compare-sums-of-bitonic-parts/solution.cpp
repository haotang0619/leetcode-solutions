class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum1 = nums[0], sum2 = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) sum1 += nums[i];
            else {
                if(sum2 == 0) sum2 += nums[i - 1];
                sum2 += nums[i];
            }
        }
        return sum1 > sum2 ? 0 : (sum1 < sum2 ? 1 : -1);
    }
};
