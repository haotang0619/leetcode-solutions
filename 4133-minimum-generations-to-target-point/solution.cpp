class Solution {
public:
    int getHash(vector<int>& p) {
        return p[0] * 7 * 7 + p[1] * 7 + p[2];
    }

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        int ans = 0, maxCnt = 7 * 7 * 7, t = getHash(target);
        vector<bool> v(maxCnt, false);
        for(auto &p : points) {
            int hash = getHash(p);
            if(hash == t) return ans;
            v[hash] = true;
        }
        
        while(true) {
            ans++;
            vector<vector<int>> newPoints;
            for(auto &p1 : points) {
                for(auto &p2 : points) {
                    if(getHash(p1) == getHash(p2)) continue;
                    vector<int> newP = {(p1[0] + p2[0]) / 2, (p1[1] + p2[1]) / 2, (p1[2] + p2[2]) / 2};
                    
                    int newHash = getHash(newP);
                    if(newHash == t) return ans;
                    if(!v[newHash]) {
                        newPoints.push_back(newP);
                        v[newHash] = true;
                    }
                }
            }
            if(newPoints.size() == 0) break;
            for(auto &p : newPoints) points.push_back(p);
        }
        return -1;
    }
};
