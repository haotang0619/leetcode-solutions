class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        vector<int> maxLen = {1, 1};
        for(int i = 0; i < 2; i++) {
            auto bars = i == 0 ? hBars : vBars;
            int now = 1;
            for(int j = 1; j < bars.size(); j++) {
                if(bars[j] == bars[j - 1] + 1) now++;
                else {
                    maxLen[i] = max(maxLen[i], now);
                    now = 1;
                }
            }
            maxLen[i] = max(maxLen[i], now);
        }
        return pow(min(maxLen[0], maxLen[1]) + 1, 2);
    }
};
