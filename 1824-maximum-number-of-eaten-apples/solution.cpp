class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = apples.size();
        int ans = 0, d = 0;
        while(d < n || !pq.empty()) {
            if(d < n && apples[d] > 0) pq.push({d + days[d], apples[d]});
            
            while(!pq.empty() && d >= pq.top().first) pq.pop();
            if(!pq.empty()) {
                auto [rd, cnt] = pq.top();
                pq.pop();
                ans++;
                if(cnt > 1) pq.push({rd, cnt - 1});
            }
            d++;
        }
        return ans;
    }
};
