class Solution {
public:
    // TODO: find a bs solution
    bool search(vector<int>& nums, int target) {
        for(auto x : nums) if(x == target) return true;
        return false;
    }
};
