class Solution {
public:
    void build(vector<pair<long long, int>>& v, vector<int>& coins) {
        int n = coins.size();
        for(int i = 1; i < (1 << n); i++) {
            long long mul = 1;
            int idx = 0, sign = -1, tmp = i;
            while(tmp > 0) {
                if(tmp & 1) mul = lcm(mul, coins[idx]), sign = -sign;
                idx++, tmp >>= 1;
            }
            v.push_back({mul, sign});
        }
    }

    long long getCnt(vector<pair<long long, int>>& v, long long& num) {
        long long cnt = 0;
        for(auto& [mul, sign] : v) cnt += (num / mul) * sign;
        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long mn = *min_element(coins.begin(), coins.end());
        long long l = mn, r = mn * k;
        vector<pair<long long, int>> v;
        build(v, coins);

        while(l < r) {
            long long m = l + (r - l) / 2;
            long long cnt = getCnt(v, m);
            if(cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};
