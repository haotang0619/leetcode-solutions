class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1 = 0;
        int ans2 = 0;
        int curr = 0;
        int prev = INT_MAX;
        
        for(int n : nums) {
            if(n <= prev) {
                ans1 = max(ans1, curr);
                curr = 1;
            } else curr++;
            prev = n;
        }
        ans1 = max(ans1, curr);

        curr = 0;
        prev = INT_MIN;
        for(int n : nums) {
            if(n >= prev) {
                ans2 = max(ans2, curr);
                curr = 1;
            } else curr++;
            prev = n;
        }
        ans2 = max(ans2, curr);

        return max(ans1, ans2);
    }
};
