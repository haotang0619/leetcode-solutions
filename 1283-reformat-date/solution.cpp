class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> mp;
        mp["Jan"] = "01"; mp["Feb"] = "02"; mp["Mar"] = "03"; mp["Apr"] = "04"; 
        mp["May"] = "05"; mp["Jun"] = "06"; mp["Jul"] = "07"; mp["Aug"] = "08";
        mp["Sep"] = "09"; mp["Oct"] = "10"; mp["Nov"] = "11"; mp["Dec"] = "12";
        string d, m, y, tmp;
        int state = 0;
        for(auto &c : date) {
            if(c == ' ') {
                if(state == 1) m = mp[tmp];
                state++;
            } else if(state == 0) {
                if(c >= '0' && c <= '9') d += c;
            } else if(state == 1) tmp += c;
            else y += c;
        }
        if(d.size() == 1) d = '0' + d;
        return y + '-' + m + '-' + d;
    }
};
