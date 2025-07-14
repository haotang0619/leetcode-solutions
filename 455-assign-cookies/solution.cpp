class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int n = s.size(), m = g.size();
        int i1 = 0, i2 = 0, ans = 0;
        while(i1 < n) {
            while(i2 < m && s[i1] < g[i2]) i2++;
            if(i2 < m) {
                ans++;
                i2++;
            }
            i1++;
        }
        return ans;
    }
};
