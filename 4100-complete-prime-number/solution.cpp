class Solution {
public:
    bool check(int num) {
        if(num == 1) return false;
        for(long long i = 2; i * i <= num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }
    
    bool completePrime(int num) {
        string s = to_string(num);
        for(long long now = 0, i = 0; i < s.size(); i++) {
            now = now * 10 + (s[i] - '0');
            cout << now << " ";
            if(!check(now)) return false;
        }
        for(long long now = 0, b = 1, i = s.size() - 1; i >= 0; i--, b *= 10) {
            now += (s[i] - '0') * b;
            if(!check(now)) return false;
        }
        return true;
    }
};
