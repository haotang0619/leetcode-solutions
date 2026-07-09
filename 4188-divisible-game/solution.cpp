class Solution {
public:
    int mod = 1e9 + 7;
    int divisibleGame(vector<int>& nums) {
        int n = nums.size(), bestK = INT_MAX;
        long long bestScore = LLONG_MIN;
        
        set<int> p = {2};
        for(auto& num : nums) {
            for(int i = 1; i * i <= num; i++) {
                if(num % i != 0) continue;
                if(i > 1) p.insert(i);
                int j = num / i;
                if(i != j && j > 1) p.insert(j);
            }
        }
        
        for(auto& i : p) {
            long long now = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j] % i == 0) now += nums[j];
                else now -= nums[j];
                if(bestScore < now) bestScore = now, bestK = i;
                if(now < 0) now = 0;
            }
        }
        long long ans = (bestScore * bestK) % mod;
        return ans < 0 ? (ans + mod) : ans;
    }
};
