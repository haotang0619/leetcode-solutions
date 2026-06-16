class Solution {
public:
    using ull = unsigned long long;

    int repeatedStringMatch(string a, string b) {
        int m = a.size(), n = b.size();
        int maxLen = m + n - 1;
        ull base = 131;
        ull hashA = 0, hashB = 0;
        for(int i = 0; i < n; i++) {
            int num = b[i] - 'a' + 1;
            hashB = hashB * base + num;
        }
        ull reduce = base;
        for(int i = 2; i <= n - 1; i++) reduce *= base;
        for(int i = 0; i < maxLen; i++) {
            if(i >= n) hashA -= reduce * (a[(i - n) % m] - 'a' + 1);
            int num = a[i % m] - 'a' + 1;
            hashA = hashA * base + num;
            if(hashA == hashB) return ceil((double)(i + 1) / m);
        }
        return -1;
    }
};
