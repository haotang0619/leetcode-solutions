class Solution {
public:
    // Saw solutions & asked GPT
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0, cost = 0;
        int n = nums.size();
        deque<pair<long long, int>> dq;
        for(int l = n, r = n - 1; r >= 0; r--) {
            while(cost <= k && l >= 0) {
                l--;
                if(l < 0) break;
                long long cnt = 0;
                while(!dq.empty() && dq.back().first <= nums[l]) {
                    auto [nowNum, nowCnt] = dq.back();
                    cost += nowCnt * (nums[l] - nowNum);
                    cnt += nowCnt;
                    dq.pop_back();
                }
                dq.push_back({nums[l], cnt + 1});
            }
            ans += r - l;
            auto [nowNum, nowCnt] = dq.front();
            dq.pop_front();
            if(nowCnt > 1) dq.push_front({nowNum, nowCnt - 1});
            cost -= nowNum - nums[r];
        }
        return ans;
    }
};
