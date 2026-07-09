class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long n1 = 0, n2 = 0;
        for(auto c : s) {
            if(c != '0') n1 = n1 * 10 + (c - '0'), n2 += (c - '0');
        }
        return n1 * n2;
    }
};
