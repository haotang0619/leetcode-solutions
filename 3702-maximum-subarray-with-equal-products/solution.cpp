class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0, n = nums.size(), mx = 1;
        for(int x = 2; x <= 10; x++) mx *= x;
        for(int i = 0; i < n; i++) {
            int g = nums[i], l = nums[i], p = nums[i];
            for(int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]), l = lcm(l, nums[j]), p *= nums[j];
                if(p > mx) break;
                if(p == g * l) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
