class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        if(limit * 3 < n) return 0;
        for(int i = min(n, limit); i >= 0; i--) {
            int j = min(n - i, i), k = n - i - j;
            if(k > j || j > i) break;
            if(i == j && j == k) ans++;
            else {
                int m = (j + k) / 2;
                ans += (j - m - 1) * 6;
                if((j + k) % 2 == 0) ans += 3;
                if(i == j) ans += 3;
                else ans += 6;
            }
        }
        return ans;
    }
};
