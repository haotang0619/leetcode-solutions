class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i = 0, j = 0, n1 = series1.size(), n2 = series2.size();
        vector<vector<int>> ans;
        while(i < n1 && j < n2) {
            int t1 = series1[i][0], v1 = series1[i][1];
            int t2 = series2[j][0], v2 = series2[j][1];
            if(t1 < t2) {
                ans.push_back({t1, v1 + v2});
                i++;
            } else if(t1 > t2) {
                ans.push_back({t2, v1 + v2});
                j++;
            } else {
                ans.push_back({t2, v1 + v2});
                i++, j++;
            }
        }
        while(i < n1) ans.push_back(series1[i++]);
        while(j < n2) ans.push_back(series2[j++]);
        return ans;
    }
};
