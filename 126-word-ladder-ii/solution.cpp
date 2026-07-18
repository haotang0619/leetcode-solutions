class Solution {
public:
    vector<int> dijkstra(vector<vector<int>>& e, int start) {
        int n = e.size();
        queue<pair<int, int>> qu; // [d, u]
        qu.push({0, start});
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        while(!qu.empty()) {
            auto [d, u] = qu.front();
            qu.pop();
            if(d > dist[u]) continue;
            for(auto& v : e[u]) {
                if(d + 1 >= dist[v]) continue;
                dist[v] = d + 1;
                qu.push({dist[v], v});
            }
        }
        return dist;
    }

    void traverse(vector<string>& wordList, vector<vector<int>>& e, vector<vector<string>>& ans, vector<string>& now, vector<int>& dist1, vector<int>& dist2, int& endIdx, int u) {
        if(u == endIdx) {
            ans.push_back(now);
            return;
        }
        int d1 = now.size() - 1, d2 = dist2[0] - d1;
        if(d1 >= dist1[endIdx]) return;
        for(auto& v : e[u]) {
            if(dist1[v] < d1 + 1 || dist2[v] > d2 - 1) continue;
            now.push_back(wordList[v - 1]);
            traverse(wordList, e, ans, now, dist1, dist2, endIdx, v);
            now.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int endIdx = -1, m = beginWord.size(), n = wordList.size();
        unordered_map<string, int> mp;
        for(int i = 0; i <= n; i++) {
            string& s = (i == 0 ? beginWord : wordList[i - 1]);
            if(i > 0 && s == beginWord) continue;
            if(s == endWord) endIdx = i;
            mp[s] = i;
        }
        if(endIdx == -1) return {};
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
        vector<int> dist1 = dijkstra(e, 0), dist2 = dijkstra(e, endIdx);
        vector<vector<string>> ans;
        vector<string> now = {beginWord};
        traverse(wordList, e, ans, now, dist1, dist2, endIdx, 0);
        return ans;
    }
};
