class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length(), l2 = b.length();
        int len = max(l1, l2);
        int carry = 0;
        string ans;
        for(int i = 0; i < len; i++) {
            int n1 = i >= l1 ? 0 : (a[l1 - 1 - i] == '1' ? 1 : 0);
            int n2 = i >= l2 ? 0 : (b[l2 - 1 - i] == '1' ? 1 : 0);
            int sum = n1 + n2 + carry;
            int n3 = sum % 2;
            carry = sum / 2;
            ans.push_back(n3 == 1 ? '1' : '0');
        }
        if(carry == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
