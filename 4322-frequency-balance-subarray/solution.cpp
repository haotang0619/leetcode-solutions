class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for(int i = 0; i < n; i++) {
            int maxFreq = 0;
            unordered_map<int, int> mpcnt, mpfreq;
            for(int j = i; j < n; j++) {
                int cnt = ++mpcnt[nums[j]];
                mpfreq[cnt]++;
                if(cnt > 1) mpfreq[cnt - 1]--;
                maxFreq = max(maxFreq, cnt);
                int len = j - i + 1;
                if(maxFreq == len) {
                    ans = max(ans, len);
                    continue;
                }
                if(maxFreq % 2 != 0) continue;
                if(mpfreq[maxFreq] > 1 && mpfreq[maxFreq / 2] == 0) continue;
                if(mpfreq[maxFreq] * maxFreq + mpfreq[maxFreq / 2] * maxFreq / 2 == len) {
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
