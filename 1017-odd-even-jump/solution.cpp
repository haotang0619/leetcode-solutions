class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> e(n, vector<int>(2, -1));
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        stack<int> sk1, sk2;
        sort(indices.begin(), indices.end(), [&](int &a, int &b) {
            if(arr[a] != arr[b]) return arr[a] < arr[b];
            return a < b;
        });
        for(int i = 0; i < n; i++) {
            while(!sk1.empty() && sk1.top() <= indices[i]) {
                int idx = sk1.top();
                sk1.pop();
                e[idx][0] = indices[i];
            }
            sk1.push(indices[i]);
        }
        sort(indices.begin(), indices.end(), [&](int &a, int &b) {
            if(arr[a] != arr[b]) return arr[a] > arr[b];
            return a < b;
        });
        for(int i = 0; i < n; i++) {
            while(!sk2.empty() && sk2.top() <= indices[i]) {
                int idx = sk2.top();
                sk2.pop();
                e[idx][1] = indices[i];
            }
            sk2.push(indices[i]);
        }
        
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int now = i, cnt = 0;
            vector<int> path = {now};
            while(now != n - 1 && now != -1) {
                now = e[now][(cnt++) % 2];
                if(now != -1) path.push_back(now);
            }
            for(int j = 0; j < path.size(); j += 2) {
                if(now == n - 1 && !vis[path[j]]) ans++;
                vis[path[j]] = true;
            }
        }
        return ans;
    }
};
