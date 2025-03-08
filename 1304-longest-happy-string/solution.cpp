class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});
        
        string ans;
        while(!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            if(pq.empty()) {
                if(p.first >= 3) {
                    ans += p.second; ans += p.second;
                    break;
                } else {
                    for(int i = 0; i < p.first; i++) ans += p.second;
                }
            } else {
                pair<int, char> np = pq.top();
                pq.pop();
                if(p.first - np.first >= 2) {
                    ans += p.second; ans += p.second; ans += np.second;
                    if(p.first - 2 > 0) pq.push({p.first - 2, p.second});
                    if(np.first - 1 > 0) pq.push({np.first - 1, np.second});
                } else {
                    ans += p.second; ans += np.second;
                    if(p.first - 1 > 0) pq.push({p.first - 1, p.second});
                    if(np.first - 1 > 0) pq.push({np.first - 1, np.second});
                }
            }
        }
        return ans;
    }
};
