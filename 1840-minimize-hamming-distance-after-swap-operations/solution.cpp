class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        map<int, vector<int>> e;
        for(auto x : allowedSwaps) {
            e[x[0]].push_back(x[1]);
            e[x[1]].push_back(x[0]);
        }
        set<int> visit;
        stack<int> sk;
        int cnt = 0, n = source.size();
        for(int x = 0; x < n; x++) {
            if(visit.contains(x)) continue;
            vector<int> s, t;
            visit.insert(x);
            sk.push(x);
            while(!sk.empty()) {
                int top = sk.top();
                sk.pop();
                s.push_back(source[top]);
                t.push_back(target[top]);
                for(auto &y : e[top]) {
                    if(visit.contains(y)) continue;
                    visit.insert(y);
                    sk.push(y);
                }
            }
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            int i = 0, j = 0;
            while(i < s.size() && j < t.size()) {
                if(s[i] == t[j]) cnt++, i++, j++;
                else if(s[i] > t[j]) j++;
                else i++;
            }
        }

        return n - cnt;
    }
};
