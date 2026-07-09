class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        // Odd numbers:
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
              if(i % 2 == 1 && n / i - i / 2 >= 1) ans++;
              int j = n / i;
              if(i == j) continue;
              if(j % 2 == 1 && n / j - j / 2 >= 1) ans++;
            }
        }
        // Even numbers:
        for(int i = 2; i <= n; i += 2) {
            if((double)n / i - ((double)i / 2 - 0.5) < 1) break;
            if(n % i == i / 2) ans++;
        }
        return ans;
    }
};
