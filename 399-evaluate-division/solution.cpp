class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        for(int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            mp[a][b] = 1.0 / values[i];
            mp[b][a] = values[i];
        }
        vector<double> ans;
        for(auto &q : queries) {
            string a = q[0], b = q[1];
            stack<pair<string, double>> sk;
            sk.push({b, 1.0});
            unordered_set<string> vis;
            vis.insert(b);
            bool valid = false;
            while(!sk.empty() && !valid) {
                auto [top, now] = sk.top();
                sk.pop();
                for(auto &kv : mp[top]) {
                    string s = kv.first;
                    double val = kv.second;
                    if(s == a) {
                        ans.push_back(now * val);
                        valid = true;
                        break;
                    } else if(!vis.contains(s)) {
                        vis.insert(s);
                        sk.push({s, now * val});
                    }
                }
            }
            if(!valid) ans.push_back(-1.0);
        }
        return ans;
    }
};
