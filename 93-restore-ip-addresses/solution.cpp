class Solution {
public:
    void findAns(vector<string>& ans, string& now, string& s, int i, int cnt) {
        if(i == s.size()) {
            if(cnt == 3) {
                string tmp = "";
                for(int j = 0; j <= now.size(); j++) {
                    if(j == now.size() || now[j] == '.') {
                        if(tmp.size() == 0 || tmp.size() > 1 && tmp[0] == '0' || tmp.size() > 3) return;
                        int x = stoi(tmp);
                        if(x > 255) return;
                        tmp = "";
                    } else tmp += now[j];
                }
                ans.push_back(now);
            }
            return;
        }
        now += s[i];
        findAns(ans, now, s, i + 1, cnt);
        now.pop_back();
        if(cnt < 3) {
            now += s[i];
            now += '.';
            findAns(ans, now, s, i + 1, cnt + 1);
            now.pop_back();
            now.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string now;
        findAns(ans, now, s, 0, 0);
        return ans;
    }
};
