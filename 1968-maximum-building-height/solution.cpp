// Saw discussions
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.size() == 0) return n - 1;
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        for(int i = 0; i < m; i++) {
            int prevI = 1, prevH = 0;
            if(i > 0) prevI = restrictions[i - 1][0], prevH = restrictions[i - 1][1];
            restrictions[i][1] = min(restrictions[i][1], prevH + restrictions[i][0] - prevI);
        }
        for(int i = m - 2; i >= 0; i--) {
            int nextI = restrictions[i + 1][0], nextH = restrictions[i + 1][1];
            restrictions[i][1] = min(restrictions[i][1], nextH + nextI - restrictions[i][0]);
        }
        int ans = 0, h = 0, x = 1;
        for(auto &res : restrictions) {
            int x1 = res[0], h1 = res[1];
            int hRise = (x1 - x + h1 - h) / 2;
            ans = max(ans, h + hRise);
            x = x1, h = h1;
        }
        ans = max(ans, restrictions[m - 1][1] + n - restrictions[m - 1][0]);
        return ans;
    }
};
