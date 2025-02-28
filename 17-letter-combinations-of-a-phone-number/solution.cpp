class Solution {
public:
    map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void findAns(vector<string>& ans, string& digits, string& curr, int idx) {
        if(idx == digits.length()) {
            ans.push_back(curr);
            return;
        }
        for(auto x : mp[digits[idx]]) {
            curr.push_back(x);
            findAns(ans, digits, curr, idx + 1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string curr;
        findAns(ans, digits, curr, 0);
        return ans;
    }
};
