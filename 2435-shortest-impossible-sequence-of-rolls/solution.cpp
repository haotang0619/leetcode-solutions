// Saw 2 hints
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> st;
        int ans = 1;
        for(auto& r : rolls) {
            st.insert(r);
            if(st.size() == k) ans++, st.clear();
        }
        return ans;
    }
};
