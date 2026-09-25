// Learned pbds from this
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    int mod = 1e9 + 7;
    int createSortedArray(vector<int>& instructions) {
        ordered_multiset<int> oms;
        int ans = 0, n = instructions.size();
        for(int i = 0; i < n; i++) {
            int val = instructions[i];
            int mnCnt = oms.order_of_key({val, -1});
            int mxCnt = i - oms.order_of_key({val, INT_MAX});
            ans = (ans + min(mnCnt, mxCnt)) % mod;
            oms.insert({val, i});
        }
        return ans;
    }
};
