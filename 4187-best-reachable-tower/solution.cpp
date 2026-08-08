class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        sort(towers.begin(), towers.end());
        vector<int> ans = {-1, -1};
        int maxQ = -1, x1 = center[0], y1 = center[1];
        for(auto& t : towers) {
            int x2 = t[0], y2 = t[1], q = t[2];
            int d = abs(x1 - x2) + abs(y1 - y2);
            if(d > radius) continue;
            if(q > maxQ) maxQ = q, ans[0] = x2, ans[1] = y2;
        }
        return ans;
    }
};
