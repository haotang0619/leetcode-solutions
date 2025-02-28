class Solution {
public:
    void findAns(set<vector<int>>& s, vector<int>& curr, int idx, int total) {
        if(idx == total) {
            s.insert(curr);
            return;
        }

        // Button 1
        for(int i = 0; i < curr.size(); i++) curr[i] = !curr[i];
        findAns(s, curr, idx + 1, total);
        for(int i = 0; i < curr.size(); i++) curr[i] = !curr[i];

        // Button 2
        for(int i = 1; i < curr.size(); i += 2) curr[i] = !curr[i];
        findAns(s, curr, idx + 1, total);
        for(int i = 1; i < curr.size(); i += 2) curr[i] = !curr[i];

        // Button 3
        for(int i = 0; i < curr.size(); i += 2) curr[i] = !curr[i];
        findAns(s, curr, idx + 1, total);
        for(int i = 0; i < curr.size(); i += 2) curr[i] = !curr[i];

        // Button 4
        for(int i = 0; i < curr.size(); i += 3) curr[i] = !curr[i];
        findAns(s, curr, idx + 1, total);
        for(int i = 0; i < curr.size(); i += 3) curr[i] = !curr[i];
    }

    int flipLights(int n, int presses) {
        int total = presses <= 2 ? presses : (presses % 2 ? 3 : 4);
        set<vector<int>> s;
        vector<int> curr(n, 1);
        findAns(s, curr, 0, total);
        return s.size();
    }
};
