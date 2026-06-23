class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> mp;
        int n = watchedVideos.size();
        vector<bool> vis(n, false);
        vis[id] = true;
        queue<pair<int, int>> qu;
        qu.push({id, 0});
        while(!qu.empty()) {
            auto [i, lv] = qu.front();
            qu.pop();
            if(lv == level) {
                for(auto &wv : watchedVideos[i]) mp[wv]++;
                continue;
            }
            for(auto &f : friends[i]) {
                if(vis[f]) continue;
                vis[f] = true;
                qu.push({f, lv + 1});
            }
        }
        vector<string> ans;
        for(auto &[s, freq] : mp) ans.push_back(s);
        sort(ans.begin(), ans.end(), [&](auto &a, auto &b) {
            if(mp[a] != mp[b]) return mp[a] < mp[b];
            return a < b;
        });
        return ans;
    }
};
