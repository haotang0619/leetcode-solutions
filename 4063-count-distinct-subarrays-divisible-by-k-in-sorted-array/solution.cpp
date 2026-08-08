class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> modCnt, tmpCnt;
        long long ans = 0, sum = 0, tmpSum = 0;
        int prev = 0, nowCnt = 0;
        for(auto& num : nums) {
            if(num != prev) {
                nowCnt = 0, tmpSum = 0;
                for(auto& [mod, cnt] : tmpCnt) modCnt[mod] += cnt;
                tmpCnt.clear();
            }
            ans += modCnt[(sum + num) % k];
            tmpCnt[sum % k]++;
            tmpSum += num;
            if(tmpSum % k == 0) ans++;
            prev = num, nowCnt++, sum += num;
        }
        return ans;
    }
};
