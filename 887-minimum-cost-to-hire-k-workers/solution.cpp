// Saw editorial, yet still not sure why this is correct
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        double ans = 1e20;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            auto [ratio, q] = v[i];
            sum += q;
            pq.push(q);
            if(i >= k) sum -= pq.top(), pq.pop();
            if(i >= k - 1) ans = min(ans, sum * ratio);
        }
        return ans;
    }
};
