class Solution {
public:
    int binaryGap(int n) {
        int ans = 0, cnt = 0;
        while(n > 0) {
            if(n & 1) ans = max(ans, cnt), cnt = 1;
            else if(cnt > 0) cnt++;
            n >>= 1;
        }
        return ans;
    }
};
