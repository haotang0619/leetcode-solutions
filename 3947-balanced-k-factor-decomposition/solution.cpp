class Solution {
public:
    int getGap(vector<int>& arr) {
        if(arr.size() == 0) return INT_MAX;
        return *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
    }

    void findAns(vector<int>& ans, vector<int>& now, vector<pair<int, int>>& primeFacs, int pidx, int kidx, int used) {
        int k = now.size(), sz = primeFacs.size();
        if(pidx == sz) {
            int gap1 = getGap(ans), gap2 = getGap(now);
            if(gap1 > gap2) ans = now;
            return;
        }
        auto& [p, cnt] = primeFacs[pidx];
        if(kidx == k - 1) {
            int mul = pow(p, cnt - used);
            now[kidx] *= mul;
            findAns(ans, now, primeFacs, pidx + 1, 0, 0);
            now[kidx] /= mul;
            return;
        }

        for(int i = 0; i <= cnt - used; i++) {
            int mul = pow(p, i);
            now[kidx] *= mul;
            findAns(ans, now, primeFacs, pidx, kidx + 1, used + i);
            now[kidx] /= mul;
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        int tmp = n;
        vector<pair<int, int>> primeFacs;
        for(long long i = 2; i <= n; i++) {
            if(!isPrime[i]) continue;
            for(long long j = i * i; j <= n; j += i) isPrime[j] = false;
            if(tmp % i == 0) {
                primeFacs.push_back({i, 0});
                while(tmp % i == 0) ++primeFacs.back().second, tmp /= i;
            }
        }
        
        vector<int> ans, now(k, 1);
        findAns(ans, now, primeFacs, 0, 0, 0);
        return ans;
    }
};
