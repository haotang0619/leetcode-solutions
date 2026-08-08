class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> pos(26, -1);
        string ans;
        int n = s.size();
        for(int i = 0, j = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(pos[idx] == -1) ans += s[i], pos[idx] = j++;
            else if(pos[idx] + k < j) ans += s[i], pos[idx] = j++;
        }
        return ans;
    }
};
