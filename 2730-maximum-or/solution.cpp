class Solution {
public:
    long long toNum(vector<int>& cnts) {
        long long base = 1, res = 0;
        for(int i = 0; i < 63; i++) {
            if(cnts[i] > 0) res += base;
            base <<= 1;
        }
        return res;
    }
    
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnts(63, 0);
        int mxIdx = 0;
        for(auto num : nums) {
            int idx = 0;
            while(num > 0) {
                if(num & 1) cnts[idx]++, mxIdx = max(mxIdx, idx);
                idx++, num >>= 1;
            }
        }
        long long ans = 0, target = 1LL << mxIdx;
        for(auto& num : nums) {
            if((num & target) == 0) continue;
            vector<int> tmp = cnts;
            long long now = num;
            int idx = 0;
            while(now > 0) {
                if(now & 1) tmp[idx]--;
                idx++, now >>= 1;
            }
            now = (long long)num << k, idx = 0;
            while(now > 0) {
                if(now & 1) tmp[idx]++;
                idx++, now >>= 1;
            }
            ans = max(ans, toNum(tmp));
        }
        return ans;
    }
};
