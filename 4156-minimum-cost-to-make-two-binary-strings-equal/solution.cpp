class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int cnt0 = 0, cnt1 = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '0' && t[i] == '1') cnt0++;
            else if(s[i] == '1' && t[i] == '0') cnt1++;
        }
        int mxcnt = max(cnt0, cnt1), mncnt = min(cnt0, cnt1);
        long long ans = 0;
        if(2 * flipCost < swapCost) ans += 2LL * flipCost * mncnt;
        else ans += (long long)swapCost * mncnt;
        mxcnt -= mncnt;
        if(mxcnt % 2 == 1) ans += flipCost, mxcnt--;
        ans += min(
            (long long)flipCost * mxcnt, 
            (long long)(crossCost + swapCost) * mxcnt / 2
        );
        return ans;
    }
};
