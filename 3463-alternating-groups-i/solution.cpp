class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        for(int i = 0; i < n; i++) {
            int l = (i - 1 + n) % n, r = (i + 1) % n;
            if(colors[l] != colors[i] && colors[i] != colors[r]) ans++;
        }
        return ans;
    }
};
