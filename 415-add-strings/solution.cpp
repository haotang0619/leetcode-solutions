class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        int carry = 0, m = num1.size(), n = num2.size(), maxmn = max(m, n);
        for(int i = 0; i < maxmn; i++) {
            int a = i < m ? (num1[i] - '0') : 0;
            int b = i < n ? (num2[i] - '0') : 0;
            int now = a + b + carry;
            carry = now / 10;
            ans += ('0' + (now % 10));
        }
        if(carry > 0) ans += ('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
