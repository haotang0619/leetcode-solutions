class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n == 1) return false;
        for(int i = 1; i * i <= n; i++) {
            if(n % i != 0) continue;
            int j = n / i;
            string sNew1, s1 = s.substr(0, i);
            while(sNew1.size() < s.size()) sNew1 += s1;
            if(sNew1 == s) return true;
            if(i != j && j != n) {
                string sNew2, s2 = s.substr(0, j);
                while(sNew2.size() < s.size()) sNew2 += s2;
                if(sNew2 == s) return true;
            }
        }
        return false;
    }
};
