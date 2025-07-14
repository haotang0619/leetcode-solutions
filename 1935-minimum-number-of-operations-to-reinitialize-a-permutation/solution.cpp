class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 1;
        for(int i = 0; i < n; i++) {
            int now = i, cnt = 0;
            do {
                cnt++;
                if(now * 2 < n) now *= 2;
                else now = now * 2 + 1 - n;
            } while(now != i);
            ans = lcm(ans, cnt);
        }
        return ans;
    }
};
