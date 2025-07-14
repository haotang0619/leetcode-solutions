class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v;
        for(char c = '0'; c <= '9'; c++) v.push_back({0, c});
        for(char c = 'A'; c <= 'Z'; c++) v.push_back({0, c});
        for(char c = 'a'; c <= 'z'; c++) v.push_back({0, c});
        for(auto x : s) {
            int idx = int(x) - (x >= 'a' ? int('a') : (x >= 'A' ? int('A') : int('0')));
            if(x >= 'a') idx += 36;
            else if(x >= 'A') idx += 10;
            v[idx].first++;
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans = "";
        for(auto [cnt, c] : v) {
            for(int i = 0; i < cnt; i++) ans += c;
        }
        return ans;
    }
};
