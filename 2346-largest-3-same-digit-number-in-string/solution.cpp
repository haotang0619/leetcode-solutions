class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i = 0; i < num.size() - 2; i++) {
            for(char c = '9'; c >= '0'; c--) {
                if(num[i] == c && num[i + 1] == c && num[i + 2] == c) {
                    ans = max(ans, num.substr(i, 3));
                }
            }
        }
        return ans;
    }
};
