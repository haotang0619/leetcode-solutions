class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_set<int> removed;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(removed.contains(j)) continue;
                int a = intervals[i][0], b = intervals[i][1], c = intervals[j][0], d = intervals[j][1];
                if(c <= a && b <= d) {
                    removed.insert(i);
                    break;
                }
            }
        }
        return n - removed.size();
    }
};
