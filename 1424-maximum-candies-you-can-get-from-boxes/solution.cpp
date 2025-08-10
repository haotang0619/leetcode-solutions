class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        queue<int> opened;
        for(int i = 0; i < n; i++) hasKey[i] = status[i] == 1;
        for(auto x : initialBoxes) {
            hasBox[x] = true;
            if(hasKey[x]) opened.push(x);
        }
        int ans = 0;
        while(!opened.empty()) {
            int front = opened.front();
            opened.pop();
            ans += candies[front];
            for(auto x : keys[front]) {
                if(!hasKey[x]) {
                    hasKey[x] = true;
                    if(hasBox[x]) opened.push(x);
                }
            }
            for(auto x : containedBoxes[front]) {
                if(!hasBox[x]) {
                    hasBox[x] = true;
                    if(hasKey[x]) opened.push(x);
                }
            }
        }
        return ans;
    }
};
