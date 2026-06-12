class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int i = -1, n = s.size();
        char prev = '\0';
        for(int j = 0; j <= n; j++) {
            if(j == n || prev != s[j]) {
                if(j - i >= 3) ans.push_back({i, j - 1});
                i = j;
            }
            prev = s[j];
        }
        return ans;
    }
};
