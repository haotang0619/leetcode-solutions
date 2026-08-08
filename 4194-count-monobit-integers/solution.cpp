class Solution {
public:
    int countMonobit(int n) {
        int ans = 1;
        for(int i = 1; i <= n; i++) {
            int now = i;
            bool valid = true;
            while(now > 0) {
                if((now & 1) == 0) {
                    valid = false;
                    break;
                }
                now >>= 1;
            }
            if(valid) ans++;
        }
        return ans;
    }
};
