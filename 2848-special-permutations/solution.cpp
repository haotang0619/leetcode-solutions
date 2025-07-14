class Solution {
public:
    int mod = 1e9 + 7;

    // Figured out by myself!
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<int> pow_of_2;
        for(int i = 0; i <= n; i++) pow_of_2.push_back((int)pow(2, i));
        vector<vector<vector<int>>> v(n, vector<vector<int>>(n, vector<int>(pow_of_2[n], 0)));
        for(int j = 0; j < n; j++) {
            int key = pow_of_2[j];
            v[0][j][key] = 1;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int num1 = nums[j];
                for(int k = 0; k < n; k++) {
                    if(k == j) continue;
                    int num2 = nums[k];
                    if(num1 % num2 == 0 || num2 % num1 == 0) {
                        for(int m = 0; m < pow_of_2[n]; m++) {
                            if((m & pow_of_2[j]) == 0) {
                                int key = m | pow_of_2[j];
                                v[i][j][key] = (v[i][j][key] + v[i - 1][k][m]) % mod;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < n; j++) {
            for(auto x : v[n - 1][j]) ans = (ans + x) % mod;
        }
        return ans;
    }
};
