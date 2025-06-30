class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_of_m = accumulate(rolls.begin(), rolls.end(), 0);
        int sum = mean * (rolls.size() + n);
        int sum_of_n = sum - sum_of_m;
        int avg_of_n = sum_of_n / n;
        int rest = sum_of_n - avg_of_n * n;
        if(sum_of_n < n || avg_of_n > 6) return {};
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) ans[i] = avg_of_n;
        for(int i = 0; i < rest; i++) {
            ans[i]++;
            if(ans[i] > 6) return {};
        }
        return ans;
    }
};
