class Solution {
public:
    bool isPalindromic(string s) {
        string s1;
        for(auto & c : s) {
            int d = (int)(c);
            string b;
            while(d > 0) {
                if(d & 1) b += '1';
                else b += '0';
                d >>= 1;
            }
            while(b.size() < 8) b += '0';
            reverse(b.begin(), b.end());
            s1 += b;
        }
        int n = s1.size();
        for(int i = 0; i < n / 2; i++) {
            if(s1[i] != s1[n - 1 - i]) return false;
        }
        return true;
    }
};
