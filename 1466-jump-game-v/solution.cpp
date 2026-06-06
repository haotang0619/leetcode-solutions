class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<vector<int>> e(n, vector<int>({}));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({arr[i], i});
            for(int j = i - 1; j >= max(0, i - d); j--) {
                if(arr[j] >= arr[i]) break;
                e[i].push_back(j);
            }
            for(int j = i + 1; j <= min(n - 1, i + d); j++) {
                if(arr[j] >= arr[i]) break;
                e[i].push_back(j);
            }
        }
        vector<int> reach(n, -1);
        int ans = -1;
        while(!pq.empty()) {
            int i = pq.top().second;
            pq.pop();
            int maxR = 0;
            for(auto x : e[i]) maxR = max(maxR, reach[x]);
            reach[i] = 1 + maxR;
            ans = max(ans, reach[i]);
        }
        return ans;
    }
};
