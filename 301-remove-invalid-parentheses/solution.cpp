class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<vector<string>> v(n + 1);
        string now;
        
        auto build = [&](auto&& self, int idx, int leftCnt) {
            if(idx == n) {
                if(leftCnt == 0) v[now.size()].push_back(now);
                return;
            }
            auto& c = s[idx];
            if(c == '(') {
                now += c;
                self(self, idx + 1, leftCnt + 1);
                now.pop_back();
                self(self, idx + 1, leftCnt);
            } else if(c == ')') {
                if(leftCnt > 0) {
                    now += c;
                    self(self, idx + 1, leftCnt - 1);
                    now.pop_back();
                }
                self(self, idx + 1, leftCnt);
            } else {
                now += c;
                self(self, idx + 1, leftCnt);
                now.pop_back();
            }
        };

        build(build, 0, 0);
        for(int i = n; i > 0; i--) {
            if(!v[i].empty()) {
                sort(v[i].begin(), v[i].end());
                v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
                return v[i];
            }
        }
        return v[0];
    }
};
