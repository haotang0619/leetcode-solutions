class Solution {
public:
    void findAns(vector<vector<int>>& ans, vector<int>& now, int& n, int& k, int i) {
        if(now.size() == k) {
            ans.push_back(now);
            return;
        }
        if(i > n) return;
        int left = k - now.size() - 1;
        for(int j = i; j + left <= n; j++) {
            now.push_back(j);
            findAns(ans, now, n, k, j + 1);
            now.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> now;
        findAns(ans, now, n, k, 1);
        return ans;
    }
};
