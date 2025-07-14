class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<vector<int>> gp(10, vector<int>({}));
        for(auto x : nums) {
            int now = 1, num = x;
            while(x > 0) {
                now = max(now, x % 10);
                x /= 10;
            }
            gp[now].push_back(num);
        }
        int ans = -1;
        for(int i = 1; i <= 9; i++) {
            if(gp[i].size() >= 2) {
                sort(gp[i].begin(), gp[i].end(), greater<int>());
                ans = max(gp[i][0] + gp[i][1], ans);
            }
        }
        return ans;
    }
};
