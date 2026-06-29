class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0, n = word.size();
        for(auto& p : patterns) {
            int m = p.size();
            for(int i = 0; i <= n - m; i++) {
                if(word.substr(i, m) == p) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
