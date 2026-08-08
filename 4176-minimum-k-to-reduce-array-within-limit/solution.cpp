class Solution {
public:
    bool check(vector<int>& nums, int k) {
        long long cnt = 0;
        for(auto& num : nums) {
            if(num % k == 0) cnt += num / k;
            else cnt += num / k + 1;
        }
        return cnt <= (long long)k * k;
    }
    
    int minimumK(vector<int>& nums) {
        int l = 1, r = 1e5;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(check(nums, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
