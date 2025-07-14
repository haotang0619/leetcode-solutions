class Solution {
public:
    vector<vector<int>> recs;
    vector<float> percentage;

    Solution(vector<vector<int>>& rects) {
        int n = rects.size();
        vector<long long> areas;
        long long total = 0;
        for(auto r : rects) {
            int a = r[0], b = r[1], x = r[2], y = r[3];
            // (Count the points)
            long long area = (long long)(x - a + 1) * (y - b + 1);
            recs.push_back(r);
            areas.push_back(area);
            total += area;
        }
        for(int i = 0; i < n; i++) {
            float p = (float)areas[i] / total;
            percentage.push_back(p);
            if(i > 0) percentage[i] += percentage[i - 1];
        }
    }
    
    vector<int> pick() {
        random_device rd;
        mt19937 gen(rd());
        
        uniform_real_distribution<float> distf(0, 1);
        float p = distf(gen);
        auto it = lower_bound(percentage.begin(), percentage.end(), p);
        int idx = it - percentage.begin();
        int x1 = recs[idx][0], x2 = recs[idx][2], y1 = recs[idx][1], y2 = recs[idx][3];
        
        uniform_int_distribution<int> dist1(x1, x2), dist2(y1, y2);
        int x = dist1(gen), y = dist2(gen);
        return vector<int>({x, y});
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
