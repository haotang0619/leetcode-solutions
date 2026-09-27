#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        // nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
        // (nums2[i] - nums1[i]) >= (nums2[j] - nums1[j]) - diff
        long long ans = 0;
        int n = nums1.size();
        ordered_multiset<int> oms;
        for(int i = 0; i < n; i++) {
            int sub = nums2[i] - nums1[i];
            ans += i - oms.order_of_key({sub - diff, -1});
            oms.insert({sub, i});
        }
        return ans;
    }
};
