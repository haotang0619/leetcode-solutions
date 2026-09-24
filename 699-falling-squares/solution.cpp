class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> points;
        for(auto& x : positions) {
            int l = x[0], r = l + x[1];
            points.insert(points.end(), {l, r - 1});
        }
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        int sz = 0;
        unordered_map<int, int> mp;
        for(auto& p : points) mp[p] = sz++;

        vector<int> ans, heights(sz, 0);
        int mx = 0;
        for(auto& x : positions) {
            int h1 = x[1], l = x[0], r = l + h1;
            int h = 0;
            for(int i = mp[l]; i <= mp[r - 1]; i++) h = max(h, heights[i]);
            for(int i = mp[l]; i <= mp[r - 1]; i++) {
                heights[i] = h + h1, mx = max(mx, h + h1);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
