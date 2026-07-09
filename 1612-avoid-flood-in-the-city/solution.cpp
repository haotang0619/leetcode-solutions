class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            if(rains[i] > 0) mp[rains[i]].push_back(i);
        }
        // [next rain day of the pond, pond idx]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        for(int i = 0; i < n; i++) {
            if(rains[i] > 0) {
                int pond = rains[i];
                int pos = upper_bound(mp[pond].begin(), mp[pond].end(), i) - mp[pond].begin();
                if(pos == mp[pond].size()) continue;
                pq.push({mp[pond][pos], pond});
            } else {
                if(pq.empty()) {
                    ans[i] = 1;
                    continue;
                }
                auto [day, pond] = pq.top();
                pq.pop();
                if(day < i) return {};
                ans[i] = pond;
            }
        }
        return pq.empty() ? ans : vector<int>({});
    }
};
