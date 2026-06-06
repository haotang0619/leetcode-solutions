class Solution {
public:
    int mirrorDistance(int n) {
        string s1 = to_string(n), s2;
        for(int i = s1.size() - 1; i >= 0; i--) s2 += s1[i];
        int m = stoi(s2);
        return abs(m - n);
    }
};
