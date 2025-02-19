class Solution {
public:
    void findAns(string &ans, string &curr, set<int> &s, int idx, string pattern) {
        if(curr.length() == pattern.length() + 1) {
            if(ans == "" || ans > curr) ans = curr;
            return;
        }
        
        char p = idx == 0 ? 'I': pattern[idx - 1];
        if(p == 'I') {
            int start = (idx == 0) ? 1 : ((curr[idx - 1] - '0') + 1);
            for(int i = start; i <= 9; i++) {
                if(s.find(i) == s.end()) {
                    s.insert(i);
                    curr += to_string(i);
                    findAns(ans, curr, s, idx + 1, pattern);
                    curr.pop_back();
                    s.erase(i);
                }
            }
        } else {
            char start = (idx == 0) ? 9 : ((curr[idx - 1] - '0') - 1);
            for(int i = start; i >= 1; i--) {
                if(s.find(i) == s.end()) {
                    s.insert(i);
                    curr += to_string(i);
                    findAns(ans, curr, s, idx + 1, pattern);
                    curr.pop_back();
                    s.erase(i);
                }
            }
        }
    }

    string smallestNumber(string pattern) {
        string ans = "";
        set<int> s;
        string curr = "";
        findAns(ans, curr, s, 0, pattern);
        return ans;
    }
};
