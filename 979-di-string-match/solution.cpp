class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(), l = 0, r = n;
        vector<int> ans;
        for(auto &c : s) {
            if(c == 'I') ans.push_back(l++);
            else ans.push_back(r--);
        }
        ans.push_back(r);
        return ans;
    }
};
