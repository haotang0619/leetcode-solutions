class Solution {
public:
    int getNum(vector<vector<int>>& cnt1, int l, int r) {
        int num = 0;
        for(int b = 1, j = 0; j < 31; b <<= 1, j++) {
            int cnt = cnt1[r + 1][j] - cnt1[l][j];
            if(cnt == r - l + 1) num |= b;
        }
        return num;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> cnt1(n + 1, vector<int>(31, 0));
        for(int i = 1; i <= n; i++) {
            for(int b = 1, j = 0; j < 31; b <<= 1, j++) {
                cnt1[i][j] = cnt1[i - 1][j] + ((nums[i - 1] & b) != 0);
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int l = i, r = n - 1;
            while(l < r) {
                int m = l + (r - l) / 2, num = getNum(cnt1, i, m);
                if(num > k) l = m + 1;
                else r = m;
            }
            int num = getNum(cnt1, i, l);
            if(num != k) continue;
            int i1 = l;
            l = i, r = n - 1;
            while(l < r) {
                int m = l + (r - l + 1) / 2, num = getNum(cnt1, i, m);
                if(num < k) r = m - 1;
                else l = m;
            }
            int i2 = l;
            ans += (i2 - i1 + 1);
        }
        return ans;
    }
};
