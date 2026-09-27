class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<vector<int>> modPos(k), negPos(k);
        modPos[0] = {0};
        long long sum = 0;
        
        for(int i = 1; i <= n; i++) {
            sum += nums[i - 1];
            int rem1 = sum % k;
            if(rem1 < 0) rem1 += k;
            if(modPos[rem1].size() < 2) modPos[rem1].push_back(i);
            else modPos[rem1].back() = i;
            
            int rem2 = (-2 * nums[i - 1]) % k;
            if(rem2 < 0) rem2 += k;
            negPos[rem2].push_back(i);
        }

        for(int r1 = 0; r1 < k; r1++) {
            for(int r2 = 0; r2 < k; r2++) {
                if(modPos[r1].size() < 1 || modPos[r2].size() < 1) continue;
                int l = modPos[r1][0], r = modPos[r2].back();
                if(r1 == r2) ans = max(ans, r - l);
                else {
                    int need;
                    if(r1 < r2) need = k - (r2 - r1);
                    else need = r1 - r2;
                    auto& v = negPos[need];
                    int lo = upper_bound(v.begin(), v.end(), l) - v.begin();
                    if(lo < v.size() && v[lo] <= r) ans = max(ans, r - l);
                }
            }
        }
        return ans;
    }
};
