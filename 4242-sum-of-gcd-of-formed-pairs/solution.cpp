class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN, n = nums.size();
        vector<int> pgcd(n);
        for(int i = 0; i < n; i++) {
            mx = max(nums[i], mx);
            pgcd[i] = gcd(nums[i], mx);
        }
        sort(pgcd.begin(), pgcd.end());
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int j = n - 1 - i;
            if(i >= j) break;
            ans += gcd(pgcd[i], pgcd[j]);
        }
        return ans;
    }
};
