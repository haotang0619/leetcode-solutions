class Solution {
public:
    int minChanges(int n, int k) {
        string s1, s2;
        while(n > 0) s1 += ('0' + (n & 1)), n >>= 1;
        while(k > 0) s2 += ('0' + (k & 1)), k >>= 1;
        int ans = 0;
        for(int i = 0; i < max(s1.size(), s2.size()); i++) {
            char c1 = (i >= s1.size()) ? '0' : s1[i];
            char c2 = (i >= s2.size()) ? '0' : s2[i];
            if(c1 == '0' && c2 == '1') return -1;
            if(c1 == '1' && c2 == '0') ans++;
        }
        return ans;
    }
};
