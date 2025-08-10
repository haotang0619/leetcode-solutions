class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> v;
        for(int i = 0; i < code.size(); i++) {
            bool valid = true;
            if(code[i] == "") continue;
            for(auto c : code[i]) {
                if(c >= 'a' && c <= 'z') valid = true;
                else if(c >= 'A' && c <= 'Z') valid = true;
                else if(c >= '0' && c <= '9') valid = true;
                else if(c == '_') valid = true;
                else {
                    valid = false;
                    break;
                }
            }
            if(!valid) continue;
            if(businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") {
                if(isActive[i]) v.push_back({businessLine[i], code[i]});
            }
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for(auto [b, c] : v) ans.push_back(c);
        return ans;
    }
};
