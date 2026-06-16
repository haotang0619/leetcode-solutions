class Solution {
public:
    bool checkGoodInteger(int n) {
        string s = to_string(n);
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            sum1 += d;
            sum2 += d * d;
        }
        return sum2 - sum1 >= 50;
    }
};
