class Solution {
public:
    struct TupleHash {
    size_t operator()(const tuple<int,int,int>& t) const {
            auto [a,b,c] = t;
            return ((size_t)a * 1315423911u)
                ^ ((size_t)b * 2654435761u)
                ^ ((size_t)c * 97531u);
        }
    };

    // mp: [type, val1, val2]
    // type 0: a - b, b - c
    // type 1: a - b, c (cnt)
    // type 2: a - c, b (cnt)
    // type 3: b - c, a (cnt)
    // type 4: b (cnt), c (cnt)
    // type 5: a (cnt), c (cnt)
    // type 6: a (cnt), b (cnt)
    void updateMap(unordered_map<tuple<int, int, int>, int, TupleHash>& mp, vector<int>& cnts, int& ans, int idx) {
        vector<tuple<int, int, int>> now(7);
        now[0] = {0, cnts[0] - cnts[1], cnts[1] - cnts[2]};
        now[1] = {1, cnts[0] - cnts[1], cnts[2]};
        now[2] = {2, cnts[0] - cnts[2], cnts[1]};
        now[3] = {3, cnts[1] - cnts[2], cnts[0]};
        now[4] = {4, cnts[1], cnts[2]};
        now[5] = {5, cnts[0], cnts[2]};
        now[6] = {6, cnts[0], cnts[1]};
        for(int i = 0; i < 7; i++) {
            if(!mp.contains(now[i])) mp[now[i]] = idx;
            else ans = max(ans, idx - mp[now[i]]);
        }
    }

    int longestBalanced(string s) {
        int ans = 0, n = s.size();
        vector<int> cnts(3, 0);
        unordered_map<tuple<int, int, int>, int, TupleHash> mp;
        mp.reserve(7 * (n + 1));
        updateMap(mp, cnts, ans, -1);
        for(int i = 0; i < n; i++) {
            cnts[s[i] - 'a']++;
            updateMap(mp, cnts, ans, i);
        }
        return ans;
    }
};
