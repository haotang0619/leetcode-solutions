class Solution {
public:
    vector<int> f = vector<int>(31, -1);

    int fib(int n) {
        if(f[n] > -1) return f[n];
        if(n == 0) {
            f[n] = 0;
            return 0;
        }
        if(n == 1) {
            f[n] = 1;
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
