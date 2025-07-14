class Solution {
public:
    string toHex(int num) {
        long long n = abs((long long)num);
        bool isNeg = num < 0;
        string ans;
        do {
            int rem = n % 16;
            if(isNeg) rem = 15 - rem;
            ans += rem < 10 ? ('0' + rem) : ('a' + rem - 10);
            n /= 16;
        } while(n > 0);
        
        if(isNeg) {
            while(ans.size() < 8) ans += 'f';
            int carry = 1;
            for(int i = 0; i < ans.size(); i++) {
                ans[i] += carry;
                if(ans[i] == ':') ans[i] = 'a';
                if(ans[i] > 'f') {
                    ans[i] = '0';
                    carry = 1;
                } else carry = 0;
                if(carry == 0) break;
            }
            if(carry == 1) ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
