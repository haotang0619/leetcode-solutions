class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int cnt0 = 0, cnt1 = 0;
        for(auto& c : s) {
            if(c == '0') cnt0++;
            else cnt1++;
        }
        vector<bool> ans;
        for(auto& str : strs) {
            int c0 = 0, c1 = 0;
            for(auto& c : str) {
                if(c == '0') c0++;
                else if(c == '1') c1++;
            }
            if(c0 > cnt0 || c1 > cnt1) {
                ans.push_back(false);
                continue;
            }
            for(auto& c : str) {
                if(c == '?') {
                    if(c0 < cnt0) c = '0', c0++;
                    else c = '1';
                }
            }
            int cnt1s = 0, cnt1str = 0;
            bool valid = true;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '1') cnt1s++;
                if(str[i] == '1') cnt1str++;
                if(cnt1s < cnt1str) {
                    valid = false;
                    break;
                }
            }
            ans.push_back(valid);
        }
        return ans;
    }
};
