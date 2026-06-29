class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occInv, int fs, int fe) {
        sort(occInv.begin(), occInv.end());
        vector<int> curr = occInv[0];
        vector<vector<int>> tmp;
        int n = occInv.size();
        for(int i = 1; i < n; i++) {
            if(occInv[i][0] > curr[1] + 1) {
                tmp.push_back(curr);
                curr = occInv[i];
            } else curr[1] = max(curr[1], occInv[i][1]);
        }
        tmp.push_back(curr);
        vector<vector<int>> ans;
        for(auto& t : tmp) {
            if(t[0] > fe || t[1] < fs) ans.push_back(t);
            else if(t[0] >= fs && t[1] <= fe) continue;
            else if(t[0] < fs && t[1] > fe) {
                ans.push_back({t[0], fs - 1});
                ans.push_back({fe + 1, t[1]});
            } else {
                if(t[0] < fs) ans.push_back({t[0], fs - 1});
                else ans.push_back({fe + 1, t[1]});
            }
        }
        return ans;
    }
};
