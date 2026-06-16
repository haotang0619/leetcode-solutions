class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxG = 0, now = 0;
        for(auto &g : gain) {
            now += g;
            maxG = max(maxG, now);
        }
        return maxG;
    }
};
