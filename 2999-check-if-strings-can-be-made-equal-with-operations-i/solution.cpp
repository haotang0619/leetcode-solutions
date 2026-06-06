class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool ans = true;
        for(int i = 0; i < 2; i++) {
            if(
                (s1[i] != s2[i] || s1[i + 2] != s2[i + 2]) &&
                (s1[i + 2] != s2[i] || s1[i] != s2[i + 2])
            ) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};
