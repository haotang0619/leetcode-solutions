class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp1;
        unordered_map<int, unordered_set<int>> mp2;
        unordered_set<int> st;
        vector<int> ans;
        
        for (auto q : queries) {
            int old_color = mp1[q[0]];
            if(old_color > 0) {
                mp2[old_color].erase(q[0]);
                if(mp2[old_color].size() == 0) st.erase(old_color);
            }
            mp1[q[0]] = q[1];
            mp2[q[1]].insert(q[0]);
            st.insert(q[1]);
            ans.push_back(st.size());
        }
        return ans;
    }
};
