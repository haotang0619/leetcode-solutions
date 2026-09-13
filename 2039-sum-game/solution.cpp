class Solution {
public:
    bool sumGame(string num) {
        int lSum = 0, rSum = 0, lCnt = 0, rCnt = 0, n = num.size();
        for(int i = 0; i < n; i++) {
            if(num[i] == '?') {
                if(i < n / 2) lCnt++;
                else rCnt++;
            } else {
                if(i < n / 2) lSum += (num[i] - '0');
                else rSum += (num[i] - '0');
            }
        }
        if((lCnt + rCnt) % 2 == 1) return true;
        int sumDiff = max(lSum, rSum) - min(lSum, rSum);
        int cntDiff = (lSum >= rSum) ? (rCnt - lCnt) : (lCnt - rCnt);
        return cntDiff / 2 * 9 != sumDiff;
    }
};
