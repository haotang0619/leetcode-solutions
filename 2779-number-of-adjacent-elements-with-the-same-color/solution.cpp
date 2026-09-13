class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int now = 0;
        vector<int> ans, colors(n, 0);
        for(auto& q : queries) {
            int idx = q[0], color = q[1];
            if(colors[idx] != color) {
                if(idx > 0 && colors[idx - 1] > 0 && colors[idx - 1] == colors[idx]) now--;
                if(idx < n - 1 && colors[idx + 1] > 0 && colors[idx] == colors[idx + 1]) now--;
                if(idx > 0 && colors[idx - 1] == color) now++;
                if(idx < n - 1 && color == colors[idx + 1]) now++;
            }
            ans.push_back(now);
            colors[idx] = color;
        }
        return ans;
    }
};
