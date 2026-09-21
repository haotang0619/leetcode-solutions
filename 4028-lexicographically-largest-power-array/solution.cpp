class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<int> ans(15, 0);
        int sz = nums.size();
        vector<pair<int, int>> intervals = {{0, sz - 1}};
        for(int i = 0; i < 15; i++) {
            int x = (1 << (14 - i));
            for(int idx = 0; idx < intervals.size(); idx++) {
                auto [left, right] = intervals[idx];
                sort(
                    nums.begin() + left,
                    nums.begin() + right + 1, 
                    [&](auto& a, auto& b) {
                        return (a & x) > (b & x);
                    }
                );
                int l = left, r = right + 1;
                while(l < r) {
                    int m = l + (r - l) / 2;
                    int now = (m <= right) ? nums[m] : 0;
                    if((now & x) > 0) l = m + 1;
                    else r = m;
                }
                ans[i] += l - left;
                if(l == left) break;
                if(l != right + 1) {
                    intervals.push_back({left, l - 1});
                    intervals.push_back({l, right});
                    intervals.erase(intervals.begin() + idx);
                    sort(intervals.begin(), intervals.end());
                    break;
                }
            }
        }
        return ans;
    }
};
