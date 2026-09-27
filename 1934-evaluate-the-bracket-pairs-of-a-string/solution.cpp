class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto& x : knowledge) mp[x[0]] = x[1];
        string ans, key;
        bool flag = false;
        for(auto& c : s) {
            if(c == '(') flag = true;
            else if(c == ')') {
                if(mp.contains(key)) ans += mp[key];
                else ans += '?';
                flag = false, key = "";
            } else if(flag) key += c;
            else ans += c;
        }
        return ans;
    }
};
