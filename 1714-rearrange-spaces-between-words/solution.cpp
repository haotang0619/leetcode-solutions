class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        string now = "";
        int cnt = 0;
        for(auto& c : text) {
            if(c == ' ') {
                cnt++;
                if(now.size() > 0) words.push_back(now);
                now = "";
            } else now += c;
        }
        if(now.size() > 0) words.push_back(now);
        int n = words.size();
        int mid = n > 1 ? (cnt / (n - 1)) : 0;
        int left = cnt - mid * (n - 1);
        string ans = "";
        for(int i = 0; i < n; i++) {
            ans += words[i];
            for(int j = 0; j < ((i == n - 1) ? left : mid); j++) ans += ' ';
        }
        return ans;
    }
};
