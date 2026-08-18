class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();
        vector<vector<int>> sSum(26, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int c = 0; c < 26; c++) {
                if(i < n - 1) sSum[c][i] = sSum[c][i + 1];
                if(s[i] == ('a' + c)) sSum[c][i]++;
            }
        }
        vector<int> pSum(26, 0);
        vector<char> v;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                int cost = INT_MAX, idx = -1;
                for(int c = 0; c < 26; c++) {
                    int now = pSum[c] + sSum[c][i];
                    if(now < cost) cost = now, idx = c;
                }
                v.push_back('a' + idx);
                pSum[idx]++;
            } else pSum[s[i] - 'a']++;
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for(auto& c : s) {
            if(c == '?') c = v[idx++];
        }
        return s;
    }
};
