class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> e(n, vector<int>({}));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(i == j) continue;
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(n, false);
        stack<int> sk;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            cnt++;
            vis[i] = true;
            sk.push(i);
            while(!sk.empty()) {
                int top = sk.top();
                sk.pop();
                for(auto x : e[top]) {
                    if(!vis[x]) {
                        vis[x] = true;
                        sk.push(x);
                    }
                }
            }
        }
        return n - cnt;
    }
};
