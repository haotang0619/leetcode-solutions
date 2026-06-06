class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int, int>> cnts;
        if(nums[0] == 0) cnts.push_back({0, 1});
        else cnts.push_back({1, 1});
        for(int i = 1; i < nums.size(); i++) {
            auto [prev, cnt] = cnts.back();
            if(nums[i] == prev) cnts.back().second++;
            else cnts.push_back({nums[i], 1});
        }
        if(cnts.size() == 1 && cnts[0].first == 1) cnts[0].second--;
        int ans = 0;
        for(int i = 0; i < cnts.size(); i++) {
            if(cnts[i].first == 1) ans = max(ans, cnts[i].second);
            if(i + 2 < cnts.size() && cnts[i].first == 1 && cnts[i + 1].first == 0 && cnts[i + 1].second == 1 && cnts[i + 2].first == 1) {
                ans = max(ans, cnts[i].second + cnts[i + 2].second);
            }
        }
        return ans;
    }
};
