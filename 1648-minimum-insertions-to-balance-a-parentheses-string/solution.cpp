class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, cnt = 0;
        for(auto& c : s) {
            if(c == '(') {
                if(cnt & 1) ans++, cnt--;
                cnt += 2;
            } else {
                if(cnt > 0) cnt--;
                else ans++, cnt++;
            }
        }
        return ans + cnt;
    }
};
