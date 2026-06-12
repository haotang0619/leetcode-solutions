class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, now = 1, maxPos = -1, minNeg = 1, maxNeg = 1;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            if(x != 0) {
                now *= x;
                if(now > 0) maxPos = now;
                else {
                    if(minNeg == 1) minNeg = now;
                    else {
                        if(maxNeg == 1) maxNeg = minNeg;
                        minNeg = now;
                    }
                }
            }
            if(x == 0 || i == n - 1) {
                if(x == 0) ans = max(ans, 0);
                if(maxPos > 0) ans = max(ans, maxPos);
                if(minNeg < 1) ans = max(ans, minNeg / maxNeg);
                now = 1, maxPos = -1, minNeg = 1, maxNeg = 1;
            } 
        }
        return ans;
    }
};
