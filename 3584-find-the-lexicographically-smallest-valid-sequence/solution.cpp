class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> lastIdx(n, -1);
        for(int i = m - 1, j = n - 1; i >= 0; i--) {
            if(word1[i] == word2[j]) lastIdx[j--] = i;
            if(j < 0) break;
        }
        vector<int> ans;
        bool changed = false;
        for(int i = 0, j = 0; i < m && j < n; i++) {
            if(word1[i] == word2[j]) ans.push_back(i), j++;
            else if(!changed && (j == n - 1 || lastIdx[j + 1] > i)) {
                changed = true, ans.push_back(i), j++;
            }
        }
        if(ans.size() < n) return {};
        return ans;
    }
};
