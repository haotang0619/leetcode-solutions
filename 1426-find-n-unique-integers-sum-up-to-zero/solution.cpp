class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i = 1; i <= n - 1; i++) ans.push_back(i);
        int sum = n * (n - 1) / 2;
        ans.push_back(-sum);
        return ans;
    }
};
