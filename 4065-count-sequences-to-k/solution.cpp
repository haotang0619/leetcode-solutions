class Solution {
public:
    int comb(int n, int m) {
        if(n < m) return 0;
        int m1 = n - m, x = max(m, m1), y = min(m, m1), j = 1;
        long long res = 1;
        for(int i = n; i > x; i--) {
            res *= i;
            while(j <= y && res % j == 0) res /= j++;
        }
        while(j <= y) res /= j++;
        return res;
    }

    void checking(int& ans, vector<int>& now, long long k) {
        if(now.size() == 0) {
            if(k == 1) ans++;
            return;
        }

        long long tot = 1;
        vector<int> cnts(7, 0);
        for(auto num : now) tot *= num, cnts[num]++;
        double x = sqrt((double)tot / k);
        long long target = (long long)x;
        if(x != target) return;

        int mul2 = 0, mul3 = 0, mul5 = 0;
        for(int i = 2; target % i == 0; i *= 2) mul2++;
        for(int i = 3; target % i == 0; i *= 3) mul3++;
        for(int i = 5; target % i == 0; i *= 5) mul5++;
        // picking 5:
        int ways5 = comb(cnts[5], mul5);
        // picking 6:
        int ways6 = 0;
        for(int i = 0; i <= cnts[6] && i <= mul2 && i <= mul3; i++) {
            // picking 3:
            int ways3 = comb(cnts[3], mul3 - i);
            // picking 4:
            int ways4 = 0;
            for(int j = 0; j <= cnts[4] && j * 2 <= mul2 - i; j++) {
                ways4 += comb(cnts[4], j) * comb(cnts[2], mul2 - i - j * 2);
            }
            ways6 += comb(cnts[6], i) * ways3 * ways4;
        }
        ans += ways5 * ways6;
    }

    void picking(int& ans, vector<int>& nums, vector<int>& now, int idx, long long k) {
        int n = nums.size();
        if(idx == n) {
            checking(ans, now, k);
            return;
        }

        if(nums[idx] != 1) {
            now.push_back(nums[idx]);
            picking(ans, nums, now, idx + 1, k);
            now.pop_back();
        }
        picking(ans, nums, now, idx + 1, k);
    }

    int countSequences(vector<int>& nums, long long k) {
        int ans = 0, cnt1 = 0;
        vector<int> now;
        for(auto num : nums) {
            if(num == 1) cnt1++;
        }
        picking(ans, nums, now, 0, k);
        return pow(3, cnt1) * ans;
    }
};
