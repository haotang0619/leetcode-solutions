class Solution {
public:
    string clearStars(string s) {
        unordered_map<char, stack<int>> ump;
        for(char c = 'a'; c <= 'z'; c++) ump[c] = stack<int>();
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                for(char c = 'a'; c <= 'z'; c++) {
                    if(!ump[c].empty()) {
                        int top = ump[c].top();
                        s[top] = '*';
                        ump[c].pop();
                        break;
                    }
                }
            } else ump[s[i]].push(i);
        }
        string ans = "";
        for(auto x : s) if(x != '*') ans += x;
        return ans;
    }
};
