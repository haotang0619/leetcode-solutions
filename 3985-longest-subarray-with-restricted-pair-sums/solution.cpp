class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> st1(mx + 1, 0), st2(mx * 2 + 1, 0);
        for(int l = 0, r = 0; r < n; r++) {
            st1[nums[r]]++;
            for(int x = l; x < r; x++) {
                int sum = nums[x] + nums[r];
                st2[sum]++;
            }
            while(true) {
                bool flag = false;
                for(int x = 1; x <= mx; x++) {
                    if(st1[x] > 0 && st2[x] > 0) {
                        flag = true;
                        break;
                    }
                }
                if(!flag) break;
                for(int x = l + 1; x <= r; x++) {
                    int sum = nums[l] + nums[x];
                    st2[sum]--;
                }
                st1[nums[l++]]--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
