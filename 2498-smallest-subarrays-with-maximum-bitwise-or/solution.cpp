class Solution {
public:
    int getNum(vector<int>& bits) {
        int num = 0;
        for(int i = 0, now = 1; i < 31; i++, now <<= 1) {
            if(bits[i] > 0) num |= now;
        }
        return num;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> cnt(31, 0), now(31, 0);
        for(auto x : nums) {
            int idx = 0;
            while(x > 0) {
                cnt[idx++] += x & 1;
                x >>= 1;
            }
        }
        int r = 0;
        vector<int> ans;
        for(int l = 0; l < nums.size(); l++) {
            int target = getNum(cnt);
            while(l == r || getNum(now) != target) {
                int idx = 0, x = nums[r++];
                while(x > 0) {
                    now[idx++] += x & 1;
                    x >>= 1;
                }
            }
            ans.push_back(r - l);
            int idx = 0, x = nums[l];
            while(x > 0) {
                cnt[idx] -= x & 1;
                now[idx++] -= x & 1;
                x >>= 1;
            }
        }
        return ans;
    }
};
