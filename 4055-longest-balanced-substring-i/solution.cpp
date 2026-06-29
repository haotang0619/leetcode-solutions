class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            vector<int> cnts(26, 0);
            int maxCnt = 0;
            for(int j = i; j < n; j++) {
                cnts[s[j] - 'a']++;
                maxCnt = max(maxCnt, cnts[s[j] - 'a']);
                bool valid = true;
                for(auto& cnt : cnts) {
                    if(cnt != 0 && cnt != maxCnt) {
                        valid = false;
                        break;
                    }
                }
                if(valid) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
