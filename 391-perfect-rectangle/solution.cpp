class Solution {
public:
    // Saw solutions
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long sum = 0, minx = 1e6, maxx = -1e6, miny = 1e6, maxy = -1e6;
        set<pair<int, int>> corners; // THIS IS THE KEY
        for(auto r : rectangles) {
            minx = min(minx, (long long)r[0]);
            miny = min(miny, (long long)r[1]);
            maxx = max(maxx, (long long)r[2]);
            maxy = max(maxy, (long long)r[3]);
            sum += (long long)(r[2] - r[0]) * (r[3] - r[1]);
            vector<pair<int, int>> v = {{r[0], r[1]}, {r[0], r[3]}, {r[2], r[1]}, {r[2], r[3]}};
            for(auto p : v) {
                if(corners.count(p) > 0) corners.erase(p);
                else corners.insert(p);
            }
        }
        
        long long area = (long long)(maxx - minx) * (maxy - miny);
        if(area != sum) return false;
        if(corners.size() != 4) return false;
        vector<pair<int, int>> v = {{minx, miny}, {minx, maxy}, {maxx, maxy}, {maxx, maxy}};
        for(auto p : v) {
            if(corners.count(p) == 0) return false;
        }
        return true;
    }
};
