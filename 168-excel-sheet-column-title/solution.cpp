class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0) {
            int remain = columnNumber % 26;
            int shift = remain > 0 ? remain - 1 : 25;
            ans += (char)((int)('A') + shift);
            columnNumber = (columnNumber - shift - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
