class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), limit = (1 << n);
        for(int i = 1; i < limit; i++) {
            bool valid = true;
            int tmp = i, idx = 0;
            vector<int> seen(1001, false);
            while(tmp > 0) {
                if(tmp & 1) {
                    int l = nums[idx] - k, r = nums[idx] + k;
                    if(l >= 1 && seen[l] || r <= 1000 && seen[r]) {
                        valid = false;
                        break;
                    }
                    seen[nums[idx]] = true;
                }
                tmp >>= 1, idx++;
            }
            if(valid) ans++;
        }
        return ans;
    }
};
