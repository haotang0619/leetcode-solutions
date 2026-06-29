class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, cnt = 0;
        for(auto &c : s) {
            if(c == 'a' && cnt > 0) cnt--, ans++;
            else if(c == 'b') cnt++;
        }
        return ans;
    }
};
