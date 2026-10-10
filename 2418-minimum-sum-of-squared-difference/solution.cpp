class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), k = k1 + k2;
        vector<long long> diff(n + 1);
        for(int i = 0; i < n; i++) diff[i] = abs(nums1[i] - nums2[i]);
        diff[n] = 0;
        sort(diff.rbegin(), diff.rend());
        
        long long ans = 0;
        for(auto& d : diff) ans += d * d;
        
        for(int i = 0; i < n && k > 0; i++) {
            long long a = diff[i], b = diff[i + 1];
            long long need = (a - b) * (i + 1);
            if(need <= k) {
                ans -= (a * a - b * b) * (i + 1);
                k -= need;
            } else {
                int quo = k / (i + 1), rem = k % (i + 1);
                long long b1 = a - quo, b2 = b1 - 1;
                ans -= (a * a - b1 * b1) * (i + 1);
                ans -= (b1 * b1 - b2 * b2) * rem;
                k = 0;
            }
        }
        return ans;
    }
};
