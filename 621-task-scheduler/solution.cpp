class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<int, int>> v(26, {1, 0}); // [avail, cnt]
        for(auto& t : tasks) v[t - 'A'].second++;
        int ans = 1, len = tasks.size();
        while(len--) {
            int minAvail = INT_MAX;
            for(int i = 0; i < 26; i++) {
                if(v[i].second > 0) minAvail = min(minAvail, v[i].first);
            }
            ans = max(ans, minAvail);
            int idx = -1, maxCnt = -1;
            for(int i = 0; i < 26; i++) {
                if(ans >= v[i].first && maxCnt < v[i].second) {
                    idx = i, maxCnt = v[i].second;
                }
            }
            v[idx].first += n + 1, v[idx].second--;
            ans++;
        }
        return ans - 1;
    }
};
