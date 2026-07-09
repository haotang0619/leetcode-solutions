class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return tasks[a][0] < tasks[b][0];
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // [time, idx]
        vector<int> ans(n);
        int i = 0, j = 0, time = 0;
        while(j < n) {
            if(pq.empty()) time = max(time, tasks[indices[j]][0]);
            while(j < n && tasks[indices[j]][0] <= time) {
                pq.push({tasks[indices[j]][1], indices[j++]});
            }
            if(!pq.empty()) {
                auto [t, idx] = pq.top();
                pq.pop();
                ans[i++] = idx;
                time += t;
            };
        }
        while(!pq.empty()) {
            ans[i++] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
