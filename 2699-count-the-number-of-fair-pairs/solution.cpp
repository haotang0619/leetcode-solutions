class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long cnt1 = 0, cnt2 = 0;
        int size = nums.size();
        int i = 0, j = size - 1;
        while(i < j) {
            if(nums[i] + nums[j] < lower) {
                cnt1 += j - i;
                i++;
            } else j--;
        }
        i = 0, j = size - 1;
        while(i < j) {
            if(nums[i] + nums[j] > upper) {
                cnt2 += j - i;
                j--;
            } else i++;
        }
        return (long long)size * (size - 1) / 2 - cnt1 - cnt2;
    }
};
