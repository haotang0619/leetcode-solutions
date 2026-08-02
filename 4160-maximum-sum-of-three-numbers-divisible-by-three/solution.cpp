class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> v(3);
        for(auto& num : nums) v[num % 3].push_back(num);
        for(int i = 0; i < 3; i++) sort(v[i].rbegin(), v[i].rend());
        int ans = 0;
        int sz1 = v[0].size(), sz2 = v[1].size(), sz3 = v[2].size();
        if(sz1 >= 3) ans = v[0][0] + v[0][1] + v[0][2];
        if(sz1 >= 1 && sz2 >= 1 && sz3 >= 1) {
            ans = max(ans, v[0][0] + v[1][0] + v[2][0]);
        }
        if(sz2 >= 3) ans = max(ans, v[1][0] + v[1][1] + v[1][2]);
        if(sz3 >= 3) ans = max(ans, v[2][0] + v[2][1] + v[2][2]);
        return ans;
    }
};
