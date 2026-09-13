class Solution {
public:
    bool findAns(vector<int>& cnts, string& ans, string& target, int idx) {
        if(idx == target.size()) return ans > target;
        int start = target[idx] - 'a';
        for(int c = start; c < 26; c++) {
            if(cnts[c] == 0) continue;
            ans += ('a' + c);
            cnts[c]--;
            if(c == start) {
                bool res = findAns(cnts, ans, target, idx + 1);
                if(res) return true;
            } else {
                for(int c = 0; c < 26; c++) {
                    for(int x = 0; x < cnts[c]; x++) ans += ('a' + c);
                }
                return true;
            }
            ans.pop_back();
            cnts[c]++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> cnts(26, 0);
        for(auto& c : s) cnts[c - 'a']++;
        string ans = "";
        if(findAns(cnts, ans, target, 0)) return ans;
        return "";
    }
};
