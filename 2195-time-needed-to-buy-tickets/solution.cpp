class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        for(int i = 0; i < tickets.size(); i++) q.push({tickets[i], i});
        int sec = 0;
        while(tickets[k] > 0) {
            sec++;
            auto [t, i] = q.front();
            q.pop();
            tickets[i]--;
            if(t - 1 > 0) q.push({t - 1, i});
        }
        return sec;
    }
};
