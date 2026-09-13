class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            string s1 = s.substr(0, i), s2 = s.substr(i), s3 = s2 + s1;
            int score = 0;
            for(int j = 0; j < n - 1; j++) {
                if(s3[j] == s3[j + 1]) score++;
            }
            if(score == k) ans++;
        }
        return ans;
    }
};
