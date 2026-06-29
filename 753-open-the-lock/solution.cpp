class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> qu;
        qu.push({"0000", 0});
        unordered_set<string> dead(deadends.begin(), deadends.end()), vis = {"0000"};
        if(dead.contains("0000")) return -1;
        if(target == "0000") return 0;
        while(!qu.empty()) {
            auto [s, step] = qu.front();
            qu.pop();
            string s1 = s;
            for(int i = 0; i < 4; i++) {
                if(s[i] == '0') s1[i] = '9';
                else s1[i] = s[i] - 1;
                if(target == s1) return step + 1;
                if(!dead.contains(s1) && !vis.contains(s1)) {
                    qu.push({s1, step + 1});
                    vis.insert(s1);
                }
                
                if(s[i] == '9') s1[i] = '0';
                else s1[i] = s[i] + 1;
                if(target == s1) return step + 1;
                if(!dead.contains(s1) && !vis.contains(s1)) {
                    qu.push({s1, step + 1});
                    vis.insert(s1);
                }

                s1[i] = s[i];
            }
        }
        return -1;
    }
};
