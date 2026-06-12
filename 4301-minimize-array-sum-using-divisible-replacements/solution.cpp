class Solution {
public:
    int maxNum = 1e5;
    long long minArraySum(vector<int>& nums) {
        vector<int> v(maxNum + 1, 0);
        for(auto n : nums) v[n]++;
        long long ans = 0;
        for(int i = 1; i <= maxNum; i++) {
            if(v[i] == 0) continue;
            for(int j = i; j <= maxNum; j += i) {
                ans += (long long)i * v[j];
                v[j] = 0;
            }
        }
        return ans;
    }
};
