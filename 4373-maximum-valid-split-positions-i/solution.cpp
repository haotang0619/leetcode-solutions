class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = -1; i < n; i++) {
            vector<int> sgcd(n + 1, 0);
            for(int j = n - 1; j >= 0; j--) {
                if(j == i) continue;
                int prev = (j + 1 == i) ? (j + 2) : (j + 1);
                sgcd[j] = gcd(sgcd[prev], nums[j]);
            }
            int now = 0, score = 0;
            for(int j = 0; j < n - 1; j++) {
                if(j == i) continue;
                now = gcd(now, nums[j]);
                int next = (j + 1 == i) ? (j + 2) : (j + 1);
                if(now == sgcd[next]) score++;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};
