class Solution {
public:
    void findAns(vector<vector<int>>& ans, vector<int>& candidates, int target, int idx, int curr, vector<int>& comb) {
        if(curr > target) return;
        if(curr == target) {
            ans.push_back(comb);
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            findAns(ans, candidates, target, i, curr + candidates[i], comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        findAns(ans, candidates, target, 0, 0, comb);
        return ans;
    }
};
