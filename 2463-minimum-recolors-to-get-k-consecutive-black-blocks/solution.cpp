class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX, n = blocks.size();
        int wcnt = 0, bcnt = 0;
        for(int i = 0; i < n; i++) {
            if(blocks[i] == 'W') wcnt++;
            else bcnt++;
            if(i >= k) {
                if(blocks[i - k] == 'W') wcnt--;
                else bcnt--;
            }
            if(i >= k - 1) ans = min(ans, wcnt);
        }
        return ans;
    }
};
