class Solution {
public:
    void findAns(vector<string>& ans, string& s, int n, int k, int cost) {
        if(cost > k) return;
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }
        for(int i = 0; i <= 1; i++) {
            if(s.size() > 0 && s[s.size() - 1] == '1' && i == 1) continue;
            s += '0' + i;
            findAns(ans, s, n, k, cost + i * (s.size() - 1));
            s.pop_back();
        }
    }
    
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string s;
        findAns(ans, s, n, k, 0);
        return ans;
    }
};
