class Solution {
public:
    void findAns(string& s, string& curr, int idx, vector<string>& ans) {
        if(idx == s.length()) {
            ans.push_back(curr);
            return;
        }

        if(isalpha(s[idx])) {
            curr.push_back(tolower(s[idx]));
            findAns(s, curr, idx + 1, ans);
            curr[idx] = toupper(s[idx]);
            findAns(s, curr, idx + 1, ans);
            curr.pop_back();
        } else {
            curr.push_back(s[idx]);
            findAns(s, curr, idx + 1, ans);
            curr.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string curr = "";
        findAns(s, curr, 0, ans);
        return ans;
    }
};
