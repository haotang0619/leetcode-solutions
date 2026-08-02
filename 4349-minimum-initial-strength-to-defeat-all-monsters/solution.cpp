class Solution {
public:
    bool check(long long s, vector<long long>& pSum, vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        for(int i = 0; i < n; i++) {
            if(s + pSum[i] < monsters[i]) return false;
            s = max(s - monsters[i], 0LL);
        }
        return true;
    }
    
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n + 1, 0);
        for(auto& b : boosts) {
            int l = b[0], r = b[1], v = b[2];
            diff[l] += v, diff[r + 1] -= v;
        }
        vector<long long> pSum(n, 0);
        pSum[0] = diff[0];
        for(int i = 1; i < n; i++) pSum[i] = pSum[i - 1] + diff[i];
        
        long long l = 0, r = LLONG_MAX;
        while(l < r) {
            long long m = l + (r - l) / 2;
            if(check(m, pSum, monsters, boosts)) r = m;
            else l = m + 1;
        }
        return l;
    }
};
