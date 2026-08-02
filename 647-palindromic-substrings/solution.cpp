class Solution {
public:
    int countSubstrings(string s) {
        string s1 = "#";
        for(auto& c : s) s1 += {c, '#'};
        int ans = 0, n = s1.size();
        cout << s1 << endl;
        for(int i = 0; i < n; i++) {
            int j = i, k = i;
            while(j >= 0 && k < n && s1[j] == s1[k]) {
                if(s1[k] != '#') ans++;
                j--, k++;
            }
        }
        return ans;
    }
};
