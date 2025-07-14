class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i = 0; i < n; i++) pq2.push(i);
        vector<int> used(n, 0);
        for(auto x : meetings) {
            long long start = x[0], end = x[1];
            while(!pq1.empty() && pq1.top().first <= start) {
                auto [s, idx] = pq1.top();
                pq1.pop();
                pq2.push(idx);
            }
            if(pq2.empty()) {
                auto [s, idx] = pq1.top();
                pq1.pop();
                pq2.push(idx);
                end += s - start;
            }
            int top = pq2.top();
            pq2.pop();
            pq1.push({end, top});
            used[top]++;
        }

        int ans = 0, maxUsed = used[0];
        for(int i = 1; i < n; i++) {
            if(maxUsed < used[i]) {
                maxUsed = used[i];
                ans = i;
            }
        }
        return ans;
    }
};
