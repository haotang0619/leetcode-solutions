class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string* s1;
        string* s2;
        if(str1.length() <= str2.length()) s1 = &str1, s2 = &str2;
        else s1 = &str2, s2 = &str1;
        int len1 = s1->length(), len2 = s2->length();

        vector<vector<int>> dp(len1, vector<int>());
        vector<int> maxLen(len1, -1);

        for(int i = 0; i < len2; i++) {
            for(int j = len1 - 1; j >= 0; j--) {
                if((*s1)[j] != (*s2)[i]) continue;
                int prevSize = maxLen[j] == -1 ? 0 : dp[maxLen[j]].size();
                if(dp[j].size() < prevSize + 1) {
                    if(maxLen[j] != -1) dp[j] = dp[maxLen[j]];
                    dp[j].push_back(j);
                }
            }
            
            int maxNow = 0;
            for(int j = 1; j < len1; j++) {
                if(maxLen[j] == -1 || dp[maxLen[j]].size() < dp[maxNow].size()) maxLen[j] = maxNow;
                if(dp[maxNow].size() < dp[j].size()) maxNow = j;
            }
        }

        
        vector<int> maxFinal = {};
        for(auto &x : dp) {
            if(x.size() > maxFinal.size()) maxFinal = x;
        }

        string ans;
        int idx1 = 0, idx2 = 0;
        for(auto j : maxFinal) {
            while(idx2 < j) ans.push_back((*s1)[idx2++]);
            while((*s2)[idx1] != (*s1)[j]) ans.push_back((*s2)[idx1++]);
            ans.push_back((*s1)[j]);
            idx1++;
            idx2++;
        }
        while(idx1 < len2) ans.push_back((*s2)[idx1++]);
        while(idx2 < len1) ans.push_back((*s1)[idx2++]);

        return ans;
    }
};
