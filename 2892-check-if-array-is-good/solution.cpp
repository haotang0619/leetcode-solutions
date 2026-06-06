class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for(auto x : nums) {
            if(x < 1 || x >= n) return false;
            cnt[x]++;
            if(x < n - 1 && cnt[x] > 1) return false;
            if(x == n - 1 && cnt[x] > 2) return false;
        }
        return true;
    }
};
