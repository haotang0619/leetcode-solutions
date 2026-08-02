class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs((long long)x));
        std::reverse(s.begin(), s.end());
        long long ans = stoll(s);
        ans = x < 0 ? -ans : ans;
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};
