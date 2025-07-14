class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(auto x : s) {
            if(x == '*') {
                if(result.size() > 0) result.pop_back();
            } else if(x == '#') result += result;
            else if(x == '%') reverse(result.begin(), result.end());
            else result += x;
        }
        return result;
    }
};
