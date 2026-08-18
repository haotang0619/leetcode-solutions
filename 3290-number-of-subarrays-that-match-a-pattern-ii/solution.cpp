class Solution {
public:
    using ull = unsigned long long;
    ull base = 131;
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        ull pHash = 0;
        for(auto& p : pattern) pHash = pHash * base + (p + 2);
        
        vector<ull> hashes(n, 0);
        vector<ull> pows(n, 1);
        for(int i = 0; i < n - 1; i++) {
            int p = 0;
            if(nums[i + 1] > nums[i]) p = 1;
            else if(nums[i + 1] < nums[i]) p = -1;
            hashes[i + 1] = hashes[i] * base + (p + 2);
            pows[i + 1] = pows[i] * base;
        }

        int ans = 0;
        for(int l = 0; l < n - m; l++) {
            int r = l + m - 1;
            ull hash = hashes[r + 1] - hashes[l] * pows[r - l + 1];
            if(hash == pHash) ans++;
        }
        return ans;
    }
};
