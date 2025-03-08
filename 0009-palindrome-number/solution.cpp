class Solution {
public:
    bool isPalindrome(int x) {
        string a = to_string(x), b = to_string(x);
        reverse(b.begin(), b.end());
        return a == b;
    }
};
