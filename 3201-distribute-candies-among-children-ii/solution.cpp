class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int max_num = min(n, limit);
        long long ans = 0;
        for(int i = max_num; i >= 0; i--) {
            int left = n - i;
            int max_left = min(left, limit);
            int ways = max_left - (left - max_left) + 1;
            if(ways >= 1) ans += ways;
        }
        return ans;
    }
};
