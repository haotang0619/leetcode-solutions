class Solution {
public:
    int factorSum(int n) {
        int sum = 0, cnt = 0;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                cnt++;
                sum += i;
                if(n / i != i) {
                    cnt++;
                    sum += n / i;
                }
            }
            if(cnt > 4) break;
        }
        return cnt == 4 ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums) ans += factorSum(x);
        return ans;
    }
};
