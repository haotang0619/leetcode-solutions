class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        bool flag = false;
        for(auto& c : s) {
            if(c == '1') cnt++, flag = false;
            else {
                if(!flag) ans += cnt, flag = true;
            }
        }
        return ans;
    }
};
