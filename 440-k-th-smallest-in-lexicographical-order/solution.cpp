class Solution {
public:
    // Saw editorial, the key is lexicographical *tree*
    int countChildren(int root, int n) {
        long long cnt = 0, left = (long long)root * 10, range = 10;
        while(left + range - 1 < (long long)n) {
            cnt += range;
            left *= 10;
            range *= 10;
        }
        cnt += max((long long)n - left + 1, 0LL);
        return (int)cnt;
    }

    int findKthNumber(int n, int k) {
        int now = 1;
        k -= 1;
        while(k > 0) {
            int cnt = countChildren(now, n);
            if(cnt >= k) {
                now *= 10;
                k -= 1;
            } else {
                now += 1;
                k -= cnt + 1;
            }
        }
        return now;
    }
};
