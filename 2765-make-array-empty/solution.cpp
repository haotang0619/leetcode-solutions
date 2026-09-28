#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        ordered_set<int> os(indices.begin(), indices.end());
        sort(indices.begin(), indices.end(), [&](auto& a, auto& b) {
            return nums[a] < nums[b];
        });
        int now = 0;
        long long ans = 0;
        for(auto& idx : indices) {
            int ord = os.order_of_key(idx), cnt = ord;
            if(now < idx) cnt -= os.order_of_key(now);
            else if(now > idx) cnt += (n - os.order_of_key(now));
            else cnt = 0;
            ans += cnt + 1;
            os.erase(idx), n--;
            if(n > 0) now = *os.find_by_order(ord % n);
        }
        return ans;
    }
};
