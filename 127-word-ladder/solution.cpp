class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int endIdx = -1, m = beginWord.size(), n = wordList.size();
        unordered_map<string, int> mp;
        for(int i = 0; i <= n; i++) {
            string& s = (i == 0 ? beginWord : wordList[i - 1]);
            if(i > 0 && s == beginWord) continue;
            if(s == endWord) endIdx = i;
            mp[s] = i;
        }
        if(endIdx == -1) return 0;
        vector<vector<int>> e(n + 1);
        for(int i = 0; i <= n; i++) {
            string& s = (i == 0 ? beginWord : wordList[i - 1]);
            if(i > 0 && s == beginWord) continue;
            for(auto& c : s) {
                char tmp = c;
                for(char c1 = 'a'; c1 <= 'z'; c1++) {
                    if(c1 == tmp) continue;
                    c = c1;
                    if(mp.contains(s) && i < mp[s]) {
                        e[i].push_back(mp[s]);
                        e[mp[s]].push_back(i);
                    }
                }
                c = tmp;
            }
        }
        queue<pair<int, int>> qu;
        qu.push({0, 1});
        vector<bool> vis(n + 1, false);
        vis[0] = true;
        while(!qu.empty()) {
            auto [u, len] = qu.front();
            qu.pop();
            if(u == endIdx) return len;
            for(auto& v : e[u]) {
                if(vis[v]) continue;
                vis[v] = true;
                qu.push({v, len + 1});
            }
        }
        return 0;
    }
};
