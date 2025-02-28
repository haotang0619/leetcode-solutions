class Solution {
public:
    string simplifyPath(string path) {
        string curr = "";
        vector<string> v;
        for(auto x : (path + '/')) {
            if(x == '/') {
                if(curr != "") {
                    if(curr == "..") {
                        if(v.size() > 0) v.pop_back();
                    } else if(curr != ".") v.push_back(curr);
                }
                curr = "";
            } else curr.push_back(x);
        }
        string ans = "/";
        for(auto x : v) ans += x + '/';
        if(ans != "/") ans.pop_back();
        return ans;
    }
};
