class Solution {
public:
    bool isPal(string& s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            if(s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }

    void findAns(vector<vector<string>>& ans, vector<string>& now, string& s, int idx) {
        int n = s.size();
        if(idx == n) {
            for(auto& str : now) {
                if(!isPal(str)) return;
            }
            ans.push_back(now);
            return;
        }
        for(int i = 1; idx + i <= n; i++) {
            now.push_back(s.substr(idx, i));
            findAns(ans, now, s, idx + i);
            now.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> now;
        findAns(ans, now, s, 0);
        return ans;
    }
};
