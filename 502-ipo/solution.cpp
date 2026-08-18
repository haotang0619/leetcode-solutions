class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<pair<int, int>> cp(n);
        for(int i = 0; i < n; i++) cp[i] = {capital[i], profits[i]};
        sort(cp.begin(), cp.end());
        int idx = 0, cnt = 0;
        priority_queue<int> pq;
        do {
            while(idx < n && cp[idx].first <= w) pq.push(cp[idx++].second);
            if(pq.empty()) break;
            w += pq.top(), pq.pop(), cnt++;
        } while(cnt < k);
        return w;
    }
};
