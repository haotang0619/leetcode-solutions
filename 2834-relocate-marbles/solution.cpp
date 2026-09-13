class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = moveFrom.size();
        for(int i = 0; i < n; i++) {
            if(st.contains(moveFrom[i])) {
                st.erase(moveFrom[i]), st.insert(moveTo[i]);
            }
        }
        vector<int> v(st.begin(), st.end());
        sort(v.begin(), v.end());
        return v;
    }
};
