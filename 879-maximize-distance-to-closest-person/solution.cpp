class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 1, prev = -1, n = seats.size();
        for(int i = 0; i <= n; i++) {
            if(i == n) {
                ans = max(ans, n - 1 - prev);
            } else if(seats[i] == 1) {
                ans = max(ans, prev == -1 ? i : ((i - prev) / 2));
                prev = i;
            }
        }
        return ans;
    }
};
