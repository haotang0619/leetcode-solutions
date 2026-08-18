class Solution {
public:
    string matToStr(vector<vector<int>>& mat) {
        string s;
        for(auto& m : mat) {
            for(auto& x : m) s += ('0' + x);
        }
        return s;
    }

    bool isAns(string& s) {
        for(auto& c : s) {
            if(c == '1') return false;
        }
        return true;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<string, int> dist;
        dist[matToStr(mat)] = 0;
        queue<pair<string, int>> qu;
        qu.push({matToStr(mat), 0});
        while(!qu.empty()) {
            auto [s, d] = qu.front();
            qu.pop();
            if(isAns(s)) return d;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    string s1 = s;
                    int idx1 = i * n + j;
                    s1[idx1] = (s1[idx1] == '0') ? '1' : '0';
                    if(j < n - 1) {
                        int idx2 = i * n + (j + 1);
                        s1[idx2] = (s1[idx2] == '0') ? '1' : '0';
                    }
                    if(i < m - 1) {
                        int idx2 = (i + 1) * n + j;
                        s1[idx2] = (s1[idx2] == '0') ? '1' : '0';
                    }
                    if(j > 0) {
                        int idx2 = i * n + (j - 1);
                        s1[idx2] = (s1[idx2] == '0') ? '1' : '0';
                    }
                    if(i > 0) {
                        int idx2 = (i - 1) * n + j;
                        s1[idx2] = (s1[idx2] == '0') ? '1' : '0';
                    }
                    if(dist.contains(s1)) continue;
                    dist[s1] = d + 1;
                    qu.push({s1, d + 1});
                }
            }
        }
        return -1;
    }
};
