class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        vector<int> v(26, 0);
        for(int i = 0, j = 0; j < n; j++) {
            int idx = s[j] - 'A';
            v[idx]++;
            bool valid = false;
            while(true) {
                int len = j - i + 1;
                for(int c = 0; c < 26; c++) {
                    if(v[c] + k >= len) {
                        valid = true;
                        ans = max(ans, len);
                    };
                }
                if(valid) break;
                int headIdx = s[i] - 'A';
                v[headIdx]--;
                i++;
            }
        }
        return ans;
    }
};
