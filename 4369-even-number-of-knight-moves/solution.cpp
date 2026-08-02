class Solution {
public:
    vector<pair<int, int>> dir = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {2, 1}, {1, 2}};
    
    bool canReach(vector<int>& start, vector<int>& target) {
        set<pair<int, int>> st;
        st.insert({start[0], start[1]});
        queue<tuple<int, int, int>> qu; // [i, j, d]
        qu.push({start[0], start[1], 0});
        while(!qu.empty()) {
            auto [i, j, d] = qu.front();
            qu.pop();
            if(i == target[0] && j == target[1]) return d % 2 == 0;
            if(i <= -7 && j <= -7 || i >= 14 && j >= 14) continue;
            for(auto& [x, y] : dir) {
                int i1 = i + x, j1 = j + y;
                if(st.contains({i1, j1})) continue;
                st.insert({i1, j1});
                qu.push({i1, j1, d + 1});
            }
        }
        return false;
    }
};
