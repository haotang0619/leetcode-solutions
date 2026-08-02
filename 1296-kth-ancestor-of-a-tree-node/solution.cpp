class TreeAncestor {
public:
    vector<vector<int>> ancestors;

    TreeAncestor(int n, vector<int>& parent) {
        ancestors.resize(n);
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(parent[i] > -1) flag = true;
            ancestors[i].push_back(parent[i]);
        }
        int now = 0;
        while(flag) {
            flag = false, now++;
            for(int i = 0; i < n; i++) {
                int prev = ancestors[i][now - 1];
                if(prev == -1) ancestors[i].push_back(-1);
                else {
                    int pprev = ancestors[prev][now - 1];
                    ancestors[i].push_back(pprev);
                    if(pprev > -1) flag = true;
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int idx = 0, now = node;
        while(k > 0) {
            if(now == -1) return -1;
            if(idx >= ancestors[now].size()) return -1;
            if(k & 1) now = ancestors[now][idx];
            k >>= 1, idx++;
        }
        return now;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
