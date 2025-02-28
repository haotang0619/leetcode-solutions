class Solution {
public:
    void findAns(int n, int k, vector<vector<int>>& ans, vector<int>& curr) {
        if(k == 0) {
            ans.push_back(curr);
            return;
        }
        int start = curr.size() > 0 ? (curr[curr.size() - 1] + 1) : 1;
        for(int i = start; i <= n; i++) {
            curr.push_back(i);
            findAns(n, k - 1, ans, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        findAns(n, k, ans, curr);
        return ans;
    }
};
