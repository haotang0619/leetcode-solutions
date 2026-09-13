class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans = n * 2;
        if(reservedSeats.size() == 0) return ans;
        sort(reservedSeats.begin(), reservedSeats.end());
        vector<int> blocked(3, false);
        int prev = -1;
        for(auto& r: reservedSeats) {
            int row = r[0], seat = r[1];
            if(prev != row) {
                if(blocked[0] && blocked[1] && blocked[2]) ans -= 2;
                else if(blocked[0] || blocked[2]) ans--;
                blocked.assign(3, false);
            }
            if(seat >= 2 && seat <= 5) blocked[0] = true;
            if(seat >= 4 && seat <= 7) blocked[1] = true;
            if(seat >= 6 && seat <= 9) blocked[2] = true;
            prev = row;
        }
        if(blocked[0] && blocked[1] && blocked[2]) ans -= 2;
        else if(blocked[0] || blocked[2]) ans--;
        return ans;
    }
};
