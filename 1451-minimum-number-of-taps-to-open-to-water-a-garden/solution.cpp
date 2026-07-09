class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxCoveredTo(n + 1, -1);
        for(int i = 0; i <= n; i++) {
            if(ranges[i] == 0) continue;
            int l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
            maxCoveredTo[l] = max(maxCoveredTo[l], r);
        }
        for(int i = 1; i <= n; i++) {
            if(maxCoveredTo[i - 1] > i) {
                maxCoveredTo[i] = max(maxCoveredTo[i], maxCoveredTo[i - 1]);
            }
        }
        int ans = 0, l = 0;
        while(l < n) {
            if(maxCoveredTo[l] == -1) return -1;
            l = maxCoveredTo[l], ans++;
        }
        return ans;
    }
};
