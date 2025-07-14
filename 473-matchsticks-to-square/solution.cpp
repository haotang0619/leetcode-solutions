class Solution {
public:
    bool solve(int idx, int &target, vector<int> &e, vector<int>& sticks) {
        if(idx == sticks.size()) {
            return e[0] == target && e[1] == target && e[2] == target && e[3] == target;
        }
        int now = sticks[idx];
        for(int i = 0; i < 4; i++) {
            if(e[i] + now <= target) {
                e[i] += now;
                bool result = solve(idx + 1, target, e, sticks);
                if(result) return true;
                e[i] -= now;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> e = {0, 0, 0, 0};
        int target = sum / 4;
        return solve(0, target, e, matchsticks);
    }
};
