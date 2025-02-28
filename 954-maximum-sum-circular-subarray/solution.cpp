class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<pair<int, int>> prefix_sum;
        int n = nums.size();
        int prev = 0;
        int ans = INT_MIN;
        for(int i = 0; i < n * 2 - 1; i++) {
            int x = nums[i % n];
            prev += x;
            if(i < n) ans = max(ans, x);
            prefix_sum.push_back({prev, i});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(prefix_sum[0]);
        for(int i = 1; i < n * 2 - 2; i++) {
            int sub = i >= n ? prefix_sum[i - n].first : 0;
            int sumHere = prefix_sum[i].first - sub;
            ans = max(ans, sumHere);
            while(pq.top().second <= i - n) pq.pop();
            ans = max(ans, prefix_sum[i].first - pq.top().first);
            pq.push(prefix_sum[i]);
        }

        return ans;
    }
};
