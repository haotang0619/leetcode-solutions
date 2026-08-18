class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxl = *max_element(lights.begin(), lights.end());
        int ans = 0;
        for(auto& arr : arrivalTime) {
            int rem = arr % period;
            if(rem >= maxl) ans = max(ans, period - rem);
        }
        return ans;
    }
};
