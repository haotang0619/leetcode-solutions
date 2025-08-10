class Solution {
public:
    string concatHex36(int n) {
        int n2 = n * n, n3 = n2 * n;
        string ans1 = "", ans2 = "";
        while(n2 > 0) {
            int mod = n2 % 16;
            ans1 += mod >= 10 ? ((mod - 10) + 'A') : (mod + '0');
            n2 /= 16;
        }
        reverse(ans1.begin(), ans1.end());
        while(n3 > 0) {
            int mod = n3 % 36;
            ans2 += mod >= 10 ? ((mod - 10) + 'A') : (mod + '0');
            n3 /= 36;
        }
        reverse(ans2.begin(), ans2.end());
        return ans1 + ans2;
    }
};
