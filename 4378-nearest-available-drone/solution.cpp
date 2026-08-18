class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx = -1, mind = INT_MAX, n = drones.size();
        int tx = target[0], ty = target[1];
        for(int i = 0; i < n; i++) {
            auto& dr = drones[i];
            int x = dr[0], y = dr[1], r = dr[2];
            int d = abs(x - tx) + abs(y - ty);
            if(d <= r) {
                if(d < mind) mind = d, idx = i;
            }
        }
        return idx;
    }
};
