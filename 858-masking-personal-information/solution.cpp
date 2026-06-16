class Solution {
public:
    string maskPII(string s) {
        int emailAtIdx = -1;
        string type = "phone";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '@') emailAtIdx = i, type = "email";
            if(type == "email" && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        if(type == "email") {
            string ans;
            char head = s[0], tail = s[emailAtIdx - 1];
            if(head >= 'A' && head <= 'Z') head = head - 'A' + 'a';
            if(tail >= 'A' && tail <= 'Z') tail = tail - 'A' + 'a';
            return string({head}) + "*****" + string({tail}) + s.substr(emailAtIdx);
        }
        int digitCnt = 0;
        string last4;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] >= '0' && s[i] <= '9') {
                if(++digitCnt <= 4) last4 = s[i] + last4;
            }
        }
        if(digitCnt == 10) return "***-***-" + last4;
        if(digitCnt == 11) return "+*-***-***-" + last4;
        if(digitCnt == 12) return "+**-***-***-" + last4;
        return "+***-***-***-" + last4;
    }
};
