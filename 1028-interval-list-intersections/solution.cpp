class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n1 = firstList.size(), n2 = secondList.size();
        while(i < n1 && j < n2) {
            int idx = (firstList[i][0] < secondList[j][0] || firstList[i][0] == secondList[j][0] && firstList[i][1] < secondList[j][1]) ? 0 : 1;
            auto &x = idx == 0 ? firstList[i] : secondList[j];
            auto &y = idx == 1 ? firstList[i] : secondList[j];
            int a1 = x[0], b1 = x[1];
            int a2 = y[0], b2 = y[1];
            if(b1 >= a2) ans.push_back({a2, min(b1, b2)});
            if(b1 <= b2) idx == 0 ? i++ : j++;
            else idx == 1 ? i++ : j++;
        }
        return ans;
    }
};
