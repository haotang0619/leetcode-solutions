class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0, prev = 0;
        for(auto& r : requests) {
            ans += abs(r - prev);
            prev = r;
        }
        return ans;
    }
};
