class Solution {
public:
    bool findAnswer(int n, vector<int> &ans, int idx, set<int> &s) {
        if(s.size() == n) return true;
        if(ans[idx] != 0) return findAnswer(n, ans, idx + 1, s);

        int maxIdx = n * 2 - 2;
        for(int i = n; i >= 1; i--) {
            if(s.find(i) == s.end()) {
                int idx2 = (i == 1) ? idx : (idx + i);
                if(ans[idx] == 0 && idx2 <= maxIdx && ans[idx2] == 0) {
                    ans[idx] = i;
                    ans[idx2] = i;
                    s.insert(i);
                    if(findAnswer(n, ans, idx + 1, s)) return true;
                    else {
                        ans[idx] = 0;
                        ans[idx2] = 0;
                        s.erase(i);
                    }
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n * 2 - 1, 0);
        set<int> s;
        findAnswer(n, ans, 0, s);
        return ans;
    }
};
