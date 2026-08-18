class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> fpos(n), lpos(m);
        for(int i = 0, j = 0, k = n - 1; i < m; i++) {
            if(j < n && station[i] == skill[j]) fpos[j++] = i;
            if(k >= 0 && station[m - 1 - i] == skill[k]) lpos[k--] = m - 1 - i;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) ans = max(ans, lpos[i + 1] - fpos[i]);
        return ans;
    }
};
