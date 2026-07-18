class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].size();
        vector<unordered_map<char, int>> mps(n);
        for(auto& v : votes) {
            for(int i = 0; i < n; i++) mps[i][v[i]]++;
        }
        sort(votes[0].begin(), votes[0].end(), [&](char& a, char& b) {
            for(int i = 0; i < n; i++) {
                if(mps[i][a] != mps[i][b]) return mps[i][a] > mps[i][b];
            }
            return a < b;
        });
        return votes[0];
    }
};
