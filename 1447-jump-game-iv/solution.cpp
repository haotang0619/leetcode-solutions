class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> mv;
        for(int i = 0; i < n; i++) mv[arr[i]].push_back(i);

        vector<int> dist(n, INT_MAX);
        map<int, bool> mp;
        queue<int> qu;
        qu.push(0);
        dist[0] = 0;
        while(!qu.empty()) {
            int top = qu.front();
            qu.pop();
            int now = dist[top];
            if(top - 1 >= 0 && dist[top - 1] > now + 1) {
                dist[top - 1] = now + 1;
                qu.push(top - 1);
            }
            if(top + 1 < n && dist[top + 1] > now + 1) {
                dist[top + 1] = now + 1;
                qu.push(top + 1);
            }
            if(!mp[arr[top]]) {
                mp[arr[top]] = true;
                for(auto x : mv[arr[top]]) {
                    if(dist[x] > now + 1) {
                        dist[x] = now + 1;
                        qu.push(x);
                    }
                }
            }
        }
        return dist[n - 1];
    }
};
