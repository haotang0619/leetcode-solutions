class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        for(auto n : nums) {
            if(st.contains(n)) return n;
            st.insert(n);
        }
        return -1;
    }
};
