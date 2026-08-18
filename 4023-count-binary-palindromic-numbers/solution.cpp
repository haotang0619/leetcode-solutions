class Solution {
public:
    vector<int> quick = {1, 2, 2, 3, 3, 4, 4, 5};
    int countBinaryPalindromes(long long n) {
        if(n < quick.size()) return quick[n];
        
        string s;
        long long n1 = n;
        while(n1 > 0) s += '0' + (n1 & 1), n1 >>= 1;
        reverse(s.begin(), s.end());
        
        int ans = 0, len = s.size();
        for(int i = 1; i < len; i++) {
            if(i == 1) ans += 2;
            else if(i % 2 == 0) ans += pow(2, i / 2 - 1);
            else ans += pow(2, i / 2);
        }
        if(len % 2 == 0) {
            string s1 = s.substr(1, len / 2 - 1);
            ans += stoi(s1, nullptr, 2);
            string s2 = s1;
            reverse(s2.begin(), s2.end());
            long long num = stoll('1' + s1 + s2 + '1', nullptr, 2);
            if(num <= n) ans++;
        } else {
            string s1 = s.substr(1, len / 2 - 1);
            ans += stoi(s1, nullptr, 2) * 2;
            if(s[len / 2] == '1') ans++;
            string s2 = s1;
            reverse(s2.begin(), s2.end());
            long long num = stoll('1' + s1 + s[len / 2] + s2 + '1', nullptr, 2);
            if(num <= n) ans++;
        }
        return ans;
    }
};
