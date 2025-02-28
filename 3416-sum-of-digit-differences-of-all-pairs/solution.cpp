class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int len = to_string(nums[0]).length();
        long long ans = 0;
        for(int i = 0; i < len; i++) {
            vector<long long> v;
            v.resize(10, 0);
            for(auto x : nums) {
                int d = (to_string(x)[i]) - '0';
                v[d]++;
            }
            long long size = nums.size();
            for(auto x : v) {
                ans += x * (size - x);
                size -= x;
            }
        }
        return ans;
    }
};
