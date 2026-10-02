class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string now;
        
        auto traverse = [&](auto&& self, int cnt) {
            if(now.size() == n * 2) {
                if(cnt == 0) ans.push_back(now);
                return;
            }
            if(cnt < n) {
                now += '(';
                self(self, cnt + 1);
                now.pop_back();
            }
            if(cnt > 0) {
                now += ')';
                self(self, cnt - 1);
                now.pop_back();
            }
        };
        traverse(traverse, 0);
        return ans;
    }
};
