class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int rem = sum % 3;
        if(rem == 0) return sum;
        int min_1_1 = 1e5, min_1_2 = 1e5, min_2_1 = 1e5, min_2_2 = 1e5;
        for(auto x : nums) {
            if(x % 3 == 1) {
                if(x < min_1_2) min_1_2 = x;
                if(min_1_2 < min_1_1) swap(min_1_1, min_1_2);
            } else if(x % 3 == 2) {
                if(x < min_2_2) min_2_2 = x;
                if(min_2_2 < min_2_1) swap(min_2_1, min_2_2);
            }
        }
        return sum - (rem == 1 ? min(min_1_1, min_2_1 + min_2_2) : min(min_2_1, min_1_1 + min_1_2));
    }
};
