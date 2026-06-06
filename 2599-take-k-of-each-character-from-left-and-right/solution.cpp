class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<vector<int>> ssum(n, {0, 0, 0});
        for(int i = n - 1; i >= 0; i--) {
            if(i < n - 1) ssum[i] = ssum[i + 1];
            ssum[i][s[i] - 'a']++;
        }
        for(int i = 0; i < 3; i++) {
            if(ssum[0][i] < k) return -1;
        }
        vector<int> cnts(3, 0);
        int ans = n;
        for(int i = 0, j = 0; i <= n; i++) {
            if(cnts[0] >= k && cnts[1] >= k && cnts[2] >= k) {
                ans = min(ans, i);
                break;
            }
            while(j < n && (cnts[0] + ssum[j][0]) >= k && (cnts[1] + ssum[j][1]) >= k && (cnts[2] + ssum[j][2]) >= k) {
                ans = min(ans, i + n - j);
                j++;
            }
            cnts[s[i] - 'a']++;
        }
        return ans;
    }
};
