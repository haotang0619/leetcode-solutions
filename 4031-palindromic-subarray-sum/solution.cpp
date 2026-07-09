class Solution {
public:
    using ll = long long;
    using ull = unsigned long long;
    int base = 131;
    
    ll getSum(vector<int>& nums) {
        int n = nums.size();
        ull b = base;
        vector<ull> rh1 = {(ull)nums[0]}, rh2 = {(ull)nums[0]}, powers = {1};
        vector<ll> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        for(int i = 1; i < n; i++) {
            rh1.push_back(rh1[i - 1] * base + nums[i]); // a, ab, abc, abcd, ...
            rh2.push_back(rh2[i - 1] + b * nums[i]);    // a, ba, cba, dcba, ...
            powers.push_back(b);
            b *= base;
        }
        ull sub = 0;
        b = 1;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            // i as the middle
            int l = i, r = min(n - 1, l + i);
            while(l < r) {
                int rIdx = l + (r - l + 1) / 2;
                int lIdx = i - (rIdx - i);
                ull leftHash = (rh1[i] - (lIdx > 0 ? rh1[lIdx - 1] * powers[i - lIdx + 1] : 0)) * b;
                ull rightHash = rh2[rIdx] - sub;
                if(leftHash == rightHash) l = rIdx;
                else r = rIdx - 1;
            }
            ans = max(ans, pSum[l + 1] - pSum[i - (l - i)]);

            sub += nums[i] * b;
            b *= base;

            // i & i + 1 as the middle
            if(i == n - 1) break;
            l = i + 1, r = min(n - 1, l + i);
            while(l < r) {
                int rIdx = l + (r - l + 1) / 2;
                int lIdx = i - (rIdx - i - 1);
                ull leftHash = (rh1[i] - (lIdx > 0 ? rh1[lIdx - 1] * powers[i - lIdx + 1] : 0)) * b;
                ull rightHash = rh2[rIdx] - sub;
                if(leftHash == rightHash) l = rIdx;
                else r = rIdx - 1;
            }
            int lIdx = i - (l - i - 1), rIdx = l;
            if(lIdx == rIdx - 1 && nums[lIdx] != nums[rIdx]) continue;
            ans = max(ans, pSum[l + 1] - pSum[i - (l - i - 1)]);
        }
        return ans;
    }
};
