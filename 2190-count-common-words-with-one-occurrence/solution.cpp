class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1, m2;
        for(auto x : words1) m1[x]++;
        for(auto x : words2) m2[x]++;
        int ans = 0;
        for(auto [w, cnt] : m1) ans += (m2[w] == 1 && cnt == 1 ? 1 : 0);
        return ans; 
    }
};
