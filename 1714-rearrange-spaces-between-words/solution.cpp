class Solution {
public:
    string reorderSpaces(string text) {
        int scnt = 0;
        string now;
        vector<string> words;
        for(auto &c : text) {
            if(c == ' ') {
                scnt++;
                if(now.size() > 0) words.push_back(now);
                now = "";
            } else now += c;
        }
        if(now.size() > 0) words.push_back(now);
        string ans;
        if(words.size() == 1) {
            ans += words[0];
            for(int i = 0; i < scnt; i++) ans += ' ';
            return ans;
        }
        int mid = scnt / (words.size() - 1), rem = scnt % (words.size() - 1);
        for(int i = 0; i < words.size(); i++) {
            ans += words[i];
            int x = i == words.size() - 1 ? rem : mid;
            for(int j = 0; j < x; j++) ans += ' ';
        }
        return ans;
    }
};
