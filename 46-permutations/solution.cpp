class Solution {
public:
    void findAns(vector<vector<int>>& ans, vector<int>& nums, vector<int> &curr, set<int> &s) {
        if(nums.size() == curr.size()) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(i) == s.end()) {
                curr.push_back(nums[i]);
                s.insert(i);
                findAns(ans, nums, curr, s);
                s.erase(i);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> curr;
        set<int> s;
        findAns(ans, nums, curr, s);
        return ans;
    }
};
