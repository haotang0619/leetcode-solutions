class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while(--n) {
            string curr;
            char prev = ans[0];
            int cnt = 1;
            for(int i = 1; i < ans.length(); i++) {
                if(ans[i] == prev) cnt++;
                else {
                    curr.push_back('0' + cnt);
                    curr.push_back(prev);
                    cnt = 1;
                }
                prev = ans[i];
            }
            curr.push_back('0' + cnt);
            curr.push_back(prev);
            ans = curr;
        }
        return ans;
    }
};
