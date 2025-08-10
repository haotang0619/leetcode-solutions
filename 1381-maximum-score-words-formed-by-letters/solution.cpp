class Solution {
public:
    void solve(int idx, int now, int &ans, vector<string>& words, vector<int> &scores, vector<vector<int>> &costs, vector<int> &nowCosts, vector<int> &totalCosts) {
        if(idx >= words.size()) {
            ans = max(ans, now);
            return;
        }
        bool flag = true;
        for(int i = 0; i < 26; i++) {
            flag = flag && nowCosts[i] + costs[idx][i] <= totalCosts[i];
        }
        if(flag) {
            for(int i = 0; i < 26; i++) nowCosts[i] += costs[idx][i];
            solve(idx + 1, now + scores[idx], ans, words, scores, costs, nowCosts, totalCosts);
            for(int i = 0; i < 26; i++) nowCosts[i] -= costs[idx][i];
        }
        solve(idx + 1, now, ans, words, scores, costs, nowCosts, totalCosts);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> scores;
        vector<vector<int>> costs;
        for(auto x : words) {
            int s = 0;
            vector<int> cost(26, 0);
            for(auto c : x) {
                int idx = c - 'a';
                s += score[idx];
                cost[idx]++;
            }
            scores.push_back(s);
            costs.push_back(cost);
        }
        
        vector<int> totalCosts(26, 0);
        for(auto c : letters) {
            totalCosts[c - 'a']++;
        }

        int ans = 0;
        vector<int> nowCosts(26, 0);
        solve(0, 0, ans, words, scores, costs, nowCosts, totalCosts);
        return ans;
    }
};
