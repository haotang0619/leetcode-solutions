class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &i, auto &j) {
            return i[1] == j[1] ? i[0] < j[0] : i[1] < j[1];
        });
        int cnt = 0, l = 1, n = events.size();
        vector<bool> v(1e5 + 1, false);
        for(auto x : events) {
            int i = max(l, x[0]);
            bool to_update = i == l;
            for(; i <= x[1]; i++) {
                if(!v[i]) {
                    v[i] = true;
                    cnt++;
                    i++;
                    break;
                }
            }
            if(to_update) l = i;
        }
        return cnt;
    }
};
