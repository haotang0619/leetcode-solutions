class Solution {
public:
    int sumOfPrimesInRange(int n) {
        vector<bool> isPrime(1001, true);
        isPrime[1] = false;
        for(int i = 2; i <= 1000; i++) {
            if(!isPrime[i]) continue;
            for(int j = i + i; j <= 1000; j += i) isPrime[j] = false;
        }
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int m = stoi(s);
        int l = min(n, m), r = max(n, m), ans = 0;
        for(int i = l; i <= r; i++) {
            if(isPrime[i]) ans += i;
        }
        return ans;
    }
};
