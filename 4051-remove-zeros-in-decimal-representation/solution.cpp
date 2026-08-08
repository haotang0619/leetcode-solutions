class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        long long ans = 0;
        for(auto& c : s) {
            if(c != '0') ans = ans * 10 + (c - '0');
        }
        return ans;
    }
};
