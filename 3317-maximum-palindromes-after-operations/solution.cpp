class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> cnts(26, 0);
        for(auto& word : words) {
            for(auto& c : word) cnts[c - 'a']++;
        }
        int ans = 0;
        sort(words.begin(), words.end(), [](auto& a, auto& b) {
            return a.size() < b.size();
        });
        for(auto& word : words) {
            int n = word.size();
            bool meet = false;
            int need = n - (n % 2);
            if(need == 0) meet = true;
            else {
                for(int i = 0; i < 26; i++) {
                    if(cnts[i] == 0) continue;
                    int add = min(cnts[i], need);
                    add = add - (add % 2);
                    cnts[i] -= add, need -= add;
                    if(need == 0) {
                        meet = true;
                        break;
                    }
                }
            }
            if(!meet) break;
            if(n % 2 == 0) {
                ans++;
                continue;
            }
            int sel = -1;
            for(int i = 0; i < 26; i++) {
                if(cnts[i] % 2 == 1) {
                    sel = i;
                    break;
                } else if(cnts[i] > 0) sel = i;
            }
            if(sel == -1) break;
            cnts[sel]--, ans++;
        }
        return ans;
    }
};
