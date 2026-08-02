class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans = 0, prev0Cnt = 0, now0Cnt = 0, maxConvert = 0;
        for(auto& c : s) {
            if(c == '1'){
                ans++;
                if(now0Cnt > 0) {
                    if(prev0Cnt > 0) maxConvert = max(maxConvert, prev0Cnt + now0Cnt);
                    prev0Cnt = now0Cnt, now0Cnt = 0;
                }
            } else now0Cnt++;
        }
        if(prev0Cnt > 0 && now0Cnt > 0) maxConvert = max(maxConvert, prev0Cnt + now0Cnt);
        return ans + maxConvert;
    }
};
