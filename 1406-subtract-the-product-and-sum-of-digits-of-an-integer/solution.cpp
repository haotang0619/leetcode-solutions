class Solution {
public:
    int subtractProductAndSum(int n) {
        long long prod = 1, sum = 0;
        string s = to_string(n);
        for(auto& c : s) {
            prod *= (c - '0'), sum += (c - '0');
        }
        return prod - sum;
    }
};
