class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, pair<int, long long>> ump;
        vector<long long> prefix_sum;
        long long ans = -1e15;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if(i == 0) prefix_sum.push_back(x);
            else prefix_sum.push_back(x + prefix_sum[i - 1]);

            int l = nums[i] - k, r = nums[i] + k;
            for(auto y : {l, r}) {
                if(ump.find(y) != ump.end()) {
                    auto [pos, sum] = ump[y];
                    long long sub_sum = prefix_sum[i] - prefix_sum[pos];
                    long long new_sum = sub_sum + sum + nums[pos];
                    ans = max(ans, new_sum);
                }
            }

            if(ump.find(x) == ump.end()) ump[x] = {i, 0LL};
            else {
                auto [pos, sum] = ump[x];
                long long sub_sum = prefix_sum[i] - prefix_sum[pos];
                long long new_sum = sub_sum + sum;
                ump[x] = {i, new_sum > 0 ? new_sum : 0LL};
            }
        }
        return ans != -1e15 ? ans : 0LL;
    }
};
