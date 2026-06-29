class Solution {
public:
    void findAns(vector<vector<int>>& ans, set<vector<int>>& st, vector<int>& nums, vector<int>& now, int idx) {
        vector<int> tmp = now;
        sort(tmp.begin(), tmp.end());
        if(!st.contains(tmp)) {
            st.insert(tmp);
            ans.push_back(tmp);
        }
        for(int i = idx; i < nums.size(); i++) {
            now.push_back(nums[i]);
            findAns(ans, st, nums, now, i + 1);
            now.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> now;
        findAns(ans, st, nums, now, 0);
        return ans;
    }
};
