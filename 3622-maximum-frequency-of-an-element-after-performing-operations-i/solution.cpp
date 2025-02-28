class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> mp;
        int maxNum = -1;
        for(auto x : nums) {
            mp[x]++;
            maxNum = max(x, maxNum);
        }
        vector<int> prefix(maxNum + 1, 0);
        for(int i = 1; i <= maxNum; i++) {
            prefix[i] = prefix[i - 1] + mp[i];
        }
        
        int ans = 0;
        for(int x = 1; x <= maxNum; x++) {
            int cnt = prefix[min(x + k, maxNum)] - prefix[max(x - k - 1, 0)] - mp[x];
            ans = max(ans, min(numOperations, cnt) + mp[x]);
        }
        return ans;
    }
};
