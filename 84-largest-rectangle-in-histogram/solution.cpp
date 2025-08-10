class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<tuple<int, int, int>> sk;
        int ans = 0;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++) {
            while(!sk.empty() && get<0>(sk.top()) >= heights[i]) {
                auto [h, prev, idx] = sk.top();
                sk.pop();
                ans = max(ans, h * (i - prev));
            }
            int prev = sk.empty() ? 0 : get<2>(sk.top()) + 1;
            cout << heights[i] << " " << prev << endl;
            sk.push({heights[i], prev, i});
        }
        return ans;
    }
};
