class Solution {
public:
    void solve(int idx, int n, string &now, vector<string> &ans) {
        if(idx >= n) {
            ans.push_back(now);
            return;
        }

        now += '1';
        solve(idx + 1, n, now, ans);
        now.pop_back();

        if(idx == 0 || now.back() != '0') {
            now += '0';
            solve(idx + 1, n, now, ans);
            now.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        string now = "";
        vector<string> ans;
        solve(0, n, now, ans);
        return ans;
    }
};
