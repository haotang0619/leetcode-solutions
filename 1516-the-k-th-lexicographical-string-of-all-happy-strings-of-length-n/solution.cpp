class Solution {
public:
    void findAns(int n, int k, int idx, string &curr, vector<string> &ans) {
        if(ans.size() >= k) return;
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        
        char prev = idx == 0 ? '\0' : curr[idx - 1];
        for(int i = 0; i <= 2; i++) {
            char c = 'a' + i;
            if(c != prev) {
                curr += c;
                findAns(n, k, idx + 1, curr, ans);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> ans;
        findAns(n, k, 0, curr, ans);
        if(ans.size() >= k) return ans[k - 1];
        return "";
    }
};
