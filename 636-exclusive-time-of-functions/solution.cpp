class Solution {
public:
    vector<string> parseLog(string &l) {
        vector<string> res;
        string now = "";
        for(auto c : l) {
            if(c == ':') {
                res.push_back(now);
                now = "";
            } else now += c;
        }
        res.push_back(now);
        return res;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<vector<int>> sk;
        for(string &l : logs) {
            auto res = parseLog(l);
            int id = stoi(res[0]), ts = stoi(res[2]);
            string type = res[1];
            if(type == "start") sk.push({id, ts, 0});
            else {
                auto top = sk.top();
                sk.pop();
                int startTs = top[1], otherTs = top[2];
                int spent = ts - startTs + 1 - otherTs;
                ans[id] += spent;
                if(!sk.empty()) {
                    auto prev = sk.top();
                    sk.pop();
                    prev[2] += spent + otherTs;
                    sk.push(prev);
                }
            }
        }
        return ans;
    }
};
