class Solution {
public:
    string getSmallestString(string s, int k) {
        string t = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(k == 0) {
                t += s[i];
                continue;
            }
            int d1 = s[i] - 'a', d2 = 26 - d1, d = min(d1, d2);
            if(d <= k) t += 'a', k -= d;
            else t += (s[i] - k), k = 0;
        }
        return t;
    }
};
