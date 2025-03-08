class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            if(i >= k - 1) {
                while(pq.top().second < i - k + 1) pq.pop();
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};
