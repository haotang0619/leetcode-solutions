class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> p = {-1, -1};
        for(auto dim : dimensions) {
            int h = dim[0], w = dim[1];
            pair<int, int> now = {pow(h, 2) + pow(w, 2), h * w};
            p = max(p, now);
        }
        return p.second;
    }
};
