class Solution {
public:
    int fac(int n) {
        int ans = 1;
        for(int i = 2; i <= n; i++) ans *= i;
        return ans;
    }

    void comb(string tiles, string prefix, int idx, int targetLen, set<string> &s) {
        if(prefix.length() == targetLen) {
            s.insert(prefix);
            return;
        }

        int len = tiles.length();
        for(int i = idx; i < len; i++) {
            comb(tiles, prefix + tiles[i], i + 1, targetLen, s);
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int ans = 0;
        int len = tiles.length();
        for(int i = 1; i <= len; i++) {
            set<string> s;
            comb(tiles, "", 0, i, s);
            for(auto str : s) {
                int added = fac(i);
                char prev = str[0];
                int cnt = 1;
                for(int j = 1; j <= str.length(); j++) {
                    if(str[j] != prev) {
                        prev = str[j];
                        added /= fac(cnt);
                        cnt = 1;
                    } else cnt++;
                }
                added /= fac(cnt);
                ans += added;
            }
        }
        return ans;
    }
};
