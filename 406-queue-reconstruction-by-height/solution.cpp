class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), [&](auto& a, auto& b) {
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        for(auto& x : people) {
            int cnt = 0, h1 = x[0], k1 = x[1];
            for(int i = 0; i < ans.size(); i++) {
                int h2 = ans[i][0], k2 = ans[i][1];
                if(h2 >= h1) cnt++;
                if(cnt > k1) {
                    ans.insert(ans.begin() + i, {h1, k1});
                    break;
                }
            }
            if(cnt <= k1) ans.push_back({h1, k1});
        }
        return ans;
    }
};
