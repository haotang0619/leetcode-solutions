class Solution {
public:
    set<long long> goods;
    vector<long long> vgoods;
    void buildGood(long long now, int idx, int type) {
        if(idx == 15) {
            if(now > 0) goods.insert(now);
            return;
        }
        if(now == 0) buildGood(now, idx + 1, 0);
        if(type == 0 || type == 1) {
            for(int i = now % 10 + 1; i <= 9; i++) {
                buildGood(now * 10 + i, idx + 1, 1);
                if(type == 0) buildGood(now * 10 + i, idx + 1, 2);
            }
        }
        if(type == 2) {
            for(int i = now % 10 - 1; i >= 0; i--) {
                buildGood(now * 10 + i, idx + 1, 2);
            }
        }
    }

    Solution() {
        buildGood(0, 0, 0);
        vgoods.assign(goods.begin(), goods.end());
    }

    long long dfs(string& s, long long memo[20][2][4][10][136], int pos, bool tight, int type, int prev, int sum) {
        if(pos == s.size()) {
            if(type == 3 && goods.contains(sum)) return 1;
            return 0;
        }
        if(memo[pos][tight][type][prev][sum] != -1) {
            return memo[pos][tight][type][prev][sum];
        }
        long long ans = 0;
        int limit = tight ? s[pos] - '0' : 9;
        for(int d = 0; d <= limit; d++) {
            bool nextTight = tight && (d == limit);
            int nextType = 0;
            if(type == 0) {
                if(prev == 0) nextType = 0;
                else {
                    if(d > prev) nextType = 1;
                    else if(d < prev) nextType = 2;
                    else nextType = 3;
                }
            } else if(type == 1) {
                if(d > prev) nextType = 1;
                else nextType = 3;
            } else if(type == 2) {
                if(d < prev) nextType = 2;
                else nextType = 3;
            } else nextType = 3;
            ans += dfs(s, memo, pos + 1, nextTight, nextType, d, sum + d);
        }
        return memo[pos][tight][type][prev][sum] = ans;
    }

    long long digitDP(long long n) {
        if(n < 0) return 0;
        string s = to_string(n);
        long long memo[20][2][4][10][136]; // [pos][tight][type][prev][sum]
        fill_n(&memo[0][0][0][0][0], 20 * 2 * 4 * 10 * 136, -1);
        return dfs(s, memo, 0, true, 0, 0, 0);
    } 
    
    long long countFancy(long long l, long long r) {
        int goodCnt = upper_bound(vgoods.begin(), vgoods.end(), r) - lower_bound(vgoods.begin(), vgoods.end(), l);
        long long fancyCnt = (digitDP(r) - digitDP(l - 1)) + goodCnt;
        return fancyCnt;
    }
};
