class Solution {
public:
    void picking(vector<int>& nums, vector<vector<int>>& mp, int idx, int end, int cnt, int sum) {
        if(idx == end) {
            mp[cnt].push_back(sum);
            return;
        }
        picking(nums, mp, idx + 1, end, cnt + 1, sum + nums[idx]);
        picking(nums, mp, idx + 1, end, cnt, sum);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / 2;
        vector<vector<int>> mp1(16), mp2(16);
        picking(nums, mp1, 0, n / 2, 0, 0);
        picking(nums, mp2, n / 2, n, 0, 0);
        int ans = INT_MAX;
        for(int i = 0; i <= n / 2; i++) sort(mp2[i].begin(), mp2[i].end());
        for(int i = 0; i <= n / 2; i++) {
            for(auto& x : mp1[i]) {
                int j = n / 2 - i, y = target - x;
                auto it = lower_bound(mp2[j].begin(), mp2[j].end(), y);
                if(it == mp2[j].end()) continue;
                int sum1 = x + *it, sum2 = sum - sum1;
                ans = min(ans, abs(sum1 - sum2));
                if(it != mp2[j].begin()) {
                    sum1 = x + *prev(it), sum2 = sum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }
        return ans;
    }
};
