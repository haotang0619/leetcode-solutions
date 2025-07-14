class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>({}));
        for(auto x : colsum) {
            if(x == 2) {
                upper--;
                lower--;
                ans[0].push_back(1);
                ans[1].push_back(1);
            } else if(x == 1) {
                if(upper > lower) {
                    ans[0].push_back(1);
                    ans[1].push_back(0);
                    upper--;
                } else {
                    ans[0].push_back(0);
                    ans[1].push_back(1);
                    lower--;
                }
            } else {
                ans[0].push_back(0);
                ans[1].push_back(0);
            }
            if(upper < 0 || lower < 0) {
                return vector<vector<int>>(0, vector<int>{});
            }
        }
        if(upper > 0 || lower > 0) {
            return vector<vector<int>>(0, vector<int>{});
        }
        return ans;
    }
};
