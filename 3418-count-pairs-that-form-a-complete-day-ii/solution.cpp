class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> cnts(24, 0);
        for(auto& hour : hours) cnts[hour % 24]++;
        for(int i = 0; i <= 12; i++) {
            if(i == 0 || i == 12) ans += (long long)cnts[i] * (cnts[i] - 1) / 2;
            else ans += (long long)cnts[i] * cnts[24 - i];
        }
        return ans;
    }
};
