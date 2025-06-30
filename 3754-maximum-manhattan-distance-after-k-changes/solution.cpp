class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0, ns = 0, ew = 0, left = k;
        vector<vector<char>> v = {{'N', 'E'}, {'N', 'W'}, {'S', 'E'}, {'S', 'W'}};
        for(auto vv : v) {
            ns = 0, ew = 0, left = k;
            for(auto x : s) {
                if(x == 'N' || x == 'S'){
                    if(x == vv[0]) {
                        if(left > 0) {
                            left--;
                            ns++;
                        } else ns--;
                    } else ns++;
                } else {
                    if(x == vv[1]) {
                        if(left > 0) {
                            left--;
                            ew++;
                        } else ew--;
                    } else ew++;
                }
                ans = max(ans, ns + ew);
            }
        }
        return ans;
    }
};
