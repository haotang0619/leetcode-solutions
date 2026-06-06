class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), ans = INT_MAX;
        for(int x = 1; x <= 6; x++) {
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for(int i = 0; i < n; i++) {
                if(tops[i] == x) cnt1++;
                if(bottoms[i] == x) cnt2++;
                if(tops[i] == x || bottoms[i] == x) cnt3++;
            }
            if(cnt3 == n) ans = min(ans, n - max(cnt1, cnt2));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
