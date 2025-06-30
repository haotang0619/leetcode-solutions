class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i += k) {
            int j = min((int)(s.size()), i + k);
            string s1 = s.substr(i, j - i);
            for(int m = j; m < i + k; m++) s1 += fill;
            ans.push_back(s1);
        }
        return ans;
    }
};
