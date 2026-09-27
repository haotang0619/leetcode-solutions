#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans = 0, n = nums.size();
        vector<long long> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        ordered_multiset<long long> oms;
        for(int i = 0; i <= n; i++) {
            // lower <= pSum[i] - x <= upper
            // x >= (pSum[i] - upper) && x <= (pSum[i] - lower)
            long long l = pSum[i] - upper, r = pSum[i] - lower;
            ans += oms.order_of_key({r, INT_MAX}) - oms.order_of_key({l, -1});
            oms.insert({pSum[i], i});
        }
        return ans;
    }
};
