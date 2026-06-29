class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            int diff1 = a[1] - a[0], diff2 = b[1] - b[0];
            if(diff1 == diff2) return a[1] > b[1];
            return diff1 > diff2;
        });
        int now = 0;
        for(auto& t : tasks) now += t[0];
        int ans = now;
        for(auto &t : tasks) {
            if(now < t[1]) ans += t[1] - now, now = t[1];
            now -= t[0];
        }
        return ans;
    }
};
