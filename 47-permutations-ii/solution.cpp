class Solution {
public:
    void findAns(set<vector<int>>& sv, vector<int>& nums, vector<int> &curr, set<int> &s) {
        if(nums.size() == curr.size()) {
            sv.insert(curr);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(i) == s.end()) {
                curr.push_back(nums[i]);
                s.insert(i);
                findAns(sv, nums, curr, s);
                s.erase(i);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> sv; 
        vector<int> curr;
        set<int> s;
        findAns(sv, nums, curr, s);
        vector<vector<int>> ans(sv.begin(), sv.end());
        return ans;
    }
};
