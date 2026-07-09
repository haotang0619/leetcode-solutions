class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<vector<int>> v(10);
        for(auto& num : nums) {
            string s = to_string(num);
            char minC = s[0], maxC = s[0];
            for(auto& c : s) {
                minC = min(minC, c);
                maxC = max(maxC, c);
            }
            v[maxC - minC].push_back(num);
        }
        for(int i = 9; i >= 0; i--) {
            if(v[i].size() == 0) continue;
            return accumulate(v[i].begin(), v[i].end(), 0);
        }
        return 0;
    }
};
