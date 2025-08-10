class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int idx = lower_bound(fruits.begin(), fruits.end(), vector<int>({startPos, 0})) - fruits.begin();
        int n = fruits.size();

        // 1-1: Go to right first
        bool flag = false;
        int used = 0, r = idx, ans1 = 0;
        while(r < n) {
            int diff = fruits[r][0] - startPos;
            if(diff <= k) {
                used = diff;
                ans1 += fruits[r++][1];
                flag = true;
            } else break;
        }
        if(flag) r--;
        // 1-2: Go back to left
        int l = idx - 1, lSum = 0, rSum = ans1;
        while(r >= idx) {
            int rPos = r < n ? fruits[r][0] : startPos;
            while(l >= 0) {
                int diff = rPos - fruits[l][0];
                if(used + diff <= k) lSum += fruits[l--][1];
                else break;
            }
            ans1 = max(ans1, lSum + rSum);
            if(l < 0) break;
            if(r < n) rSum -= fruits[r][1];
            if(r > 0) used = fruits[r - 1][0] - startPos;
            r--;
        }

        // 2-1: Go to left first
        flag = false, used = 0, l = idx - 1;
        int ans2 = 0;
        while(l >= 0) {
            int diff = startPos - fruits[l][0];
            if(diff <= k) {
                used = diff;
                ans2 += fruits[l--][1];
                flag = true;
            } else break;
        }
        if(flag) l++;
        // 2-2: Go back to right
        r = idx, rSum = 0, lSum = ans2;
        while(l <= idx - 1) {
            int lPos = l >= 0 ? fruits[l][0] : startPos;
            while(r < n) {
                int diff = fruits[r][0] - lPos;
                if(used + diff <= k) rSum += fruits[r++][1];
                else break;
            }
            ans2 = max(ans2, lSum + rSum);
            if(r >= n) break;
            if(l >= 0) lSum -= fruits[l][1];
            if(l < n) used = startPos - fruits[l + 1][0];
            l++;
        }

        return max(ans1, ans2);
    }
};
