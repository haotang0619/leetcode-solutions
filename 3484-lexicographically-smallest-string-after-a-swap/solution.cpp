class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i = 0; i < n - 1; i++) {
            int x = s[i] - '0', y = s[i + 1] - '0';
            if(((x & 1) == (y & 1)) && x > y) {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};
