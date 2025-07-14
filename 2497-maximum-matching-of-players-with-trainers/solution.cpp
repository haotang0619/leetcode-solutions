class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());
        int n = trainers.size(), m = players.size();
        int i1 = 0, i2 = 0, ans = 0;
        while(i1 < n) {
            while(i2 < m && trainers[i1] < players[i2]) i2++;
            if(i2 < m) {
                ans++;
                i2++;
            }
            i1++;
        }
        return ans;
    }
};
