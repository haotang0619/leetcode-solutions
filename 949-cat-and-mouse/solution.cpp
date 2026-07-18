// Saw editorial
// You need to know Minimax Algorithm
class Solution {
public:

    int catMouseGame(vector<vector<int>>& graph) {
        int DRAW = 0, MOUSE = 1, CAT = 2;
        int n = graph.size();
        
        map<tuple<int, int, int>, int> deg; // {mouse, cat, turn} => degree
        for(int m = 0; m < n; m++) {
            for(int c = 0; c < n; c++) {
                deg[{m, c, MOUSE}] = graph[m].size();
                deg[{m, c, CAT}] = graph[c].size();
                for(auto& node : graph[c]) {
                    if(node == 0) {
                        deg[{m, c, CAT}]--;
                        break;
                    }
                }
            }
        }

        map<tuple<int, int, int>, int> results; // {mouse, cat, turn} => draw/mouse/cat
        deque<tuple<int, int, int, int>> dq; // {mouse, cat, turn, result}
        for(int i = 0; i < n; i++) {
            for(int t = MOUSE; t <= CAT; t++) {
                results[{0, i, t}] = MOUSE;
                dq.push_back({0, i, t, MOUSE});
                if(i > 0) {
                    results[{i, i, t}] = CAT;
                    dq.push_back({i, i, t, CAT});
                }
            }
        }

        while(!dq.empty()) {
            auto [i, j, t, res] = dq.front();
            dq.pop_front();
            int t1 = 3 - t;
            auto& nodes = graph[t == 2 ? i : j];
            for(auto& v : nodes) {
                if(t == 1 && v == 0) continue;
                int i1 = (t == 2) ? v : i, j1 = (t == 1) ? v : j;
                if(!results.contains({i1, j1, t1})) results[{i1, j1, t1}] = DRAW;
                if(results[{i1, j1, t1}] == DRAW) {
                    if(t1 == res) {
                        results[{i1, j1, t1}] = res;
                        dq.push_back({i1, j1, t1, res});
                    } else {
                        if(--deg[{i1, j1, t1}] == 0) {
                            results[{i1, j1, t1}] = t;
                            dq.push_back({i1, j1, t1, t});
                        }
                    }
                }
            }
        }
        return results[{1, 2, MOUSE}];
    }
};
