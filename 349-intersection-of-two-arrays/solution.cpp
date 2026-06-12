class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;
        vector<int> ans;
        for(auto x : nums1) st1.insert(x);
        for(auto x : nums2) {
            if(st1.contains(x) && !st2.contains(x)) {
                st2.insert(x);
                ans.push_back(x);
            }
        }
        return ans;
    }
};
