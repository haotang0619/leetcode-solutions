class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int ans = 0, l = 0, r = 1e9;
        while(l < r) {
            int m = l + (r - l) / 2;
            int cnt = 1, prev = price[0];
            for(int i = 1; i < price.size() && cnt < k; i++) {
                if(price[i] - prev >= m) {
                    cnt++;
                    prev = price[i];
                }
            }
            if(cnt >= k) {
                ans = max(ans, m);
                l = m + 1;
            } else r = m;
        }
        return ans;
    }
};
