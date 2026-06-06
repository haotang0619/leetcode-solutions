class Solution {
public:
    // Saw all hints
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size(), l = 0, r = n - 1;
        long long maxCnt = (1 + n) * (long long)n / 2;
        if((long long)k > maxCnt) return -1;
        while(l < r) {
            int m = l + (r - l) / 2;
            vector<int> ord(order.begin(), order.begin() + m + 1);
            sort(ord.begin(), ord.end());
            long long cnt = 0;
            int prev = -1;
            for(auto o : ord) {
                cnt += (long long)(o - prev) * (n - o);
                prev = o;
            }
            if(cnt >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};
