class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> sSum(n);
        sSum[n - 1] = damage[n - 1];
        for(int i = n - 2; i >= 0; i--) sSum[i] = sSum[i + 1] + damage[i];
        long long ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            long long minHp = requirement[i];
            int l = 0, r = i;
            while(l < r) {
                int m = l + (r - l) / 2;
                long long totalD = sSum[m] - (i < n - 1 ? sSum[i + 1] : 0);
                if(hp - totalD < minHp) l = m + 1;
                else r = m;
            }
            if(l == i && hp - damage[l] < minHp) continue;
            ans += i - l + 1;
        }
        return ans;
    }
};
