class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int idx = -1, n = balance.size();
        for(int i = 0; i < n; i++) {
            if(balance[i] < 0) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return 0;
        int l = (idx - 1 + n) % n, r = (idx + 1) % n;
        int distl = 1, distr = 1;
        long long ans = 0;
        while(balance[idx] < 0 && distl + distr <= n) {
            bool flag = false;
            bool doRight = l != r;
            
            long long trans = min(-balance[idx], balance[l]);
            balance[idx] += trans;
            ans += trans * distl;
            flag = true;
            
            if(doRight && balance[idx] < 0) {
                long long trans = min(-balance[idx], balance[r]);
                balance[idx] += trans;
                ans += trans * distr;
                flag = true;
            }
            l = (l - 1 + n) % n, r = (r + 1) % n, distl++, distr++;
            if(!flag) return -1;
        }
        return balance[idx] >= 0 ? ans : -1;
    }
};
