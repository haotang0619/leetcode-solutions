class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> sk;
        for(auto& c : s) {
            if(sk.empty() || sk.top().first != c) sk.push({c, 1});
            else {
                auto [c1, cnt] = sk.top();
                sk.pop();
                if(cnt < k - 1) sk.push({c1, cnt + 1});
            }
        }
        string ans;
        while(!sk.empty()) {
            ans.append(sk.top().second, sk.top().first);
            sk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
