class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        for(auto& x : availableIntervals) x[0] *= 2, x[1] *= 2;
        for(auto& x : targetIntervals) x[0] *= 2, x[1] *= 2;
        
        sort(availableIntervals.begin(), availableIntervals.end());
        sort(targetIntervals.begin(), targetIntervals.end());
        vector<pair<int, int>> t;
        pair<int, int> curr = {-1, -1};
        for(auto& x : targetIntervals) {
            auto& [l, r] = curr;
            if(r >= x[0]) r = max(r, x[1]);
            else {
                if(l > -1) t.push_back(curr);
                curr = {x[0], x[1]};
            }
        }
        t.push_back(curr);
        
        int n = t.back().second + 1;
        auto it1 = availableIntervals.begin();
        auto it2 = t.begin();
        int ans = 0, until = 0;
        for(int i = 0; i < n; i++) {
            while((*it2).second < i) it2++;
            if(i < (*it2).first || i <= until) continue;
            while(it1 != availableIntervals.end() && (*it1)[0] <= i) {
                until = max(until, (*it1++)[1]);
            }
            if(until < i) return -1;
            ans++;
        }
        return ans;
    }
};
