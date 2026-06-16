// Saw some solutions
class Solution {
public:
    pair<int, int> find2Min(vector<int> &v) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(auto x : v) {
            if(min2 > x) min2 = x;
            if(min1 > min2) swap(min1, min2);
        }
        return {min1, min2};
    }

    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size(), n = units[0].size();
        long long score = 0;
        if(n == 1) {
            for(auto &x : units) score += x[0];
            return score;
        }

        // Move everyone's first_min to a single device whose {second_min, first_min} is the min pair.
        int min1st = INT_MAX; // The score for the recipient.
        int min2nd = INT_MAX; // To find the recipient.
        for(auto &x : units) {
            auto [x0, x1] = find2Min(x);
            score += x1; // The score for all the other devices.
            min1st = min(min1st, x0);
            min2nd = min(min2nd, x1);
        }
        return score - min2nd + min1st;
    }
};
