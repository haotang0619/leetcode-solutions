class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int idx1 = 0, idx2 = 1, n = colors.size(), ans = 0;
        while(idx1 < n) {
            while(colors[idx2 % n] != colors[(idx2 - 1) % n] && idx2 - idx1 < k) idx2++;
            if(idx2 - idx1 == k) ans++, idx1++;
            else idx1 = idx2, idx2++;
        }
        return ans;
    }
};
