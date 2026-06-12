class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        long long i = 1;
        int ans = 0;
        while(pow(i, k) <= (long long)r) {
            if(pow(i, k) >= l && pow(i, k) <= r) ans++;
            i++;
        }
        return ans + (l == 0 ? 1 : 0);
    }
};
