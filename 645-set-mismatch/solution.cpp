class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++) st.insert(i);
        for(auto x : nums) {
            if(st.contains(x)) st.erase(x);
            else ans.push_back(x);
        }
        ans.push_back(*(st.begin()));
        return ans;
    }
};
