class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int now = k;
        while(true) {
            if(!st.contains(now)) break;
            now += k;
        }
        return now;
    }
};
