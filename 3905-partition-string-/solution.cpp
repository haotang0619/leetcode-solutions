class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> ans;
        set<string> st;
        string now = "";
        for(auto x : s) {
            now += x;
            if(!st.count(now)) {
                st.insert(now);
                ans.push_back(now);
                now = "";
            }
        }
        return ans;
    }
};
