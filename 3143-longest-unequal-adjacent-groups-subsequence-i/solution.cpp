class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int curr = groups[0];
        vector<string> ans = {words[0]};
        for(int i = 1; i < groups.size(); i++) {
            if(curr != groups[i]) {
                curr = groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
