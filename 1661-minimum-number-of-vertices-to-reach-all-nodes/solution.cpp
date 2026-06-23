class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(int i = n - 1; i >= 0; i--) st.insert(i);
        for(auto &e : edges) st.erase(e[1]);
        return vector<int>(st.begin(), st.end());
    }
};
