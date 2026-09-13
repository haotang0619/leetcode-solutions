class Solution {
public:
    int mod = 1e9 + 7;
    int fastPow(long long a, int b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod, b >>= 1;
        }
        return res;
    }
    
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(auto num : nums) {
            long long w = num % 10, d = num / 10;
            string s = to_string(d);
            long long a = stoll(s.substr(0, w));
            long long b = stoi(s.substr(w));
            ans = (ans + fastPow(a, b)) % mod;
        }
        return ans < 0 ? (ans + mod) : ans;
    }
};
