class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> groups;
        vector<int> gpIds(c + 1);
        vector<int> minOpIds;
        vector<bool> op(c + 1, true);
        vector<vector<int>> edges(c + 1, vector<int>({}));
        for(auto x : connections) {
            int l = x[0], r = x[1];
            edges[l].push_back(r);
            edges[r].push_back(l);
        }
        vector<bool> seen(c + 1, false);
        for(int i = 1; i <= c; i++) {
            if(seen[i]) continue;
            stack<int> sk;
            sk.push(i);
            vector<int> gp;
            while(!sk.empty()) {
                int top = sk.top();
                seen[top] = true;
                gp.push_back(top);
                gpIds[top] = groups.size();
                sk.pop();
                for(auto x : edges[top]) {
                    if(!seen[x]) {
                        seen[x] = true;
                        sk.push(x);
                    }
                }
            }
            groups.push_back(gp);
        }
        for(int i = 0; i < groups.size(); i++) {
            sort(groups[i].begin(), groups[i].end());
            minOpIds.push_back(0);
        }
        vector<int> ans;
        for(auto x : queries) {
            int type = x[0], i = x[1];
            int gpId = gpIds[i];
            int gpSize = groups[gpId].size();
            int minOpId = minOpIds[gpId];
            if(type == 1) {
                if(op[i]) ans.push_back(i);
                else if(minOpId < gpSize) ans.push_back(groups[gpId][minOpId]);
                else ans.push_back(-1);
            } else {
                op[i] = false;
                while(minOpId < gpSize && !op[groups[gpId][minOpId]]) minOpId++;
                minOpIds[gpId] = minOpId;
            }
        }
        return ans;
    }
};
