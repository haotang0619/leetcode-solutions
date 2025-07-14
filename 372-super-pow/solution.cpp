class Solution {
public:
    bool divBy2(vector<int>& b) {
        bool flag = true;
        int carry = 0;
        for(int i = 0; i < b.size(); i++) {
            int old = b[i];
            b[i] = (carry * 10 + b[i]) / 2;
            carry = old % 2;
            if(b[i] != 0) flag = false;
        }
        return flag;
    }

    int mod = 1337;
    int fastPow(int a, vector<int>& b) {
        int rem = b.back() & 1;
        long long res = 1, all = a;
        while(!divBy2(b)) {
            if(rem) res = (res * all) % mod;
            all = (all * all) % mod;
            rem = b.back() & 1;
        }
        if(rem) res = (res * all) % mod;
        return (int)res;
    }

    int superPow(int a, vector<int>& b) {
        return fastPow(a, b);
    }
};
