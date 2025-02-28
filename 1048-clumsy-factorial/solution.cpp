class Solution {
public:
    int clumsy(int n) {
        int ans = 0;
        bool flag = false;
        while(n > 0) {
            int now = n;
            if(n - 1 > 0) now *= (n - 1);
            if(n - 2 > 0) now /= (n - 2);
            if(n - 3 > 0) now = flag ? (now - (n - 3)) : (now + (n - 3));
            ans = flag ? (ans - now) : (ans + now);
            flag = true;
            n -= 4;
        }
        return ans;
    }
};
