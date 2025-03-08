class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(--n) {
            string s1 = s;
            for(int i = 0; i < s1.length(); i++) s1[i] = s1[i] == '0' ? '1' : '0';
            reverse(s1.begin(), s1.end());
            s = s + "1" + s1;
        }
        return s[k - 1];
    }
};
