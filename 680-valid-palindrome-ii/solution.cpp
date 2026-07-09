class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        bool flag = false, valid1 = true, valid2 = true;
        for(int i = 0; i < n && (valid1 || valid2); i++) {
            if(!flag) {
                int j = n - 1 - i;
                if(i == j) return true;
                if(s[i] != s[j]) flag = true;
            } else {
                int i1 = i - 1, j1 = n - 1 - i;
                int i2 = i, j2 = j1 + 1;
                if(i1 < j1 && s[i1] != s[j1]) valid1 = false;
                if(i2 < j2 && s[i2] != s[j2]) valid2 = false;
                if(i1 >= j1 && i2 >= j2) break;
            }
        }
        return valid1 || valid2;
    }
};
