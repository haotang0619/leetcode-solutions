class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0, n = nums.size();
        deque<pair<int, int>> mindq, maxdq;
        for(int i = 0, j = 0; j < n; j++) {
            while(!mindq.empty() && mindq.back().first >= nums[j]) mindq.pop_back();
            mindq.push_back({nums[j], j});
            while(!maxdq.empty() && maxdq.back().first <= nums[j]) maxdq.pop_back();
            maxdq.push_back({nums[j], j});
            while(maxdq.front().first - mindq.front().first > limit) {
                i++;
                while(mindq.front().second < i) mindq.pop_front();
                while(maxdq.front().second < i) maxdq.pop_front();
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
