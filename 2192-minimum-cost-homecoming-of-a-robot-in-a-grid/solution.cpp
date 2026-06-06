class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int maxr = max(startPos[0], homePos[0]), minr = min(startPos[0], homePos[0]), maxc = max(startPos[1], homePos[1]), minc = min(startPos[1], homePos[1]);
        int ans = 0;
        for(int i = minr; i <= maxr; i++) ans += rowCosts[i];
        for(int i = minc; i <= maxc; i++) ans += colCosts[i];
        ans -= rowCosts[startPos[0]];
        ans -= colCosts[startPos[1]];
        return ans;
    }
};
