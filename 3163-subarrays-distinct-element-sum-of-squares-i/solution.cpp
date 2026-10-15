class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                unordered_set<int> st(nums.begin() + i, nums.begin() + j + 1);
                ans += st.size() * st.size();
            }
        }
        return ans;
    }
};
