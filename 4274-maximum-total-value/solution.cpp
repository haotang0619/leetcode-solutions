// Asked GPT
class Solution {
public:
    int mod = 1e9 + 7;
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size(), l = 1, r = 1e9;
        long long ans = 0;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            long long cnt = 0, cnt1 = 0, now = 0;
            for(int i = 0; i < n; i++) {
                // value[i] - decay[i] * (x - 1) >= mid; 
                // x <= (value[i] - mid) / decay[i] + 1;
                if(value[i] < mid) continue;
                int x = (value[i] - mid) / decay[i] + 1;
                cnt += x;
                if(cnt > 2 * m) break;
                long long until = value[i] - decay[i] * (x - 1);
                long long added = (value[i] + until) * x / 2;
                now += added;
                if(until == mid) cnt1++;
            }
            if(cnt <= m) ans = max(ans, now);
            else if(cnt - cnt1 <= m) {
                now -= (cnt - m) * mid;
                ans = max(ans, now);
            }
            if(l == mid) break;
            if(cnt >= m) l = mid;
            else r = mid - 1;
        }
        return ans % mod;
    }
};
