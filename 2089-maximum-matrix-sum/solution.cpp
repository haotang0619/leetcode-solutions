// Saw all hints
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int minAbs = INT_MAX, negCnt = 0;
        for(auto &mat : matrix) {
            for(auto &num : mat) {
                if(num < 0) negCnt++;
                minAbs = min(minAbs, abs(num));
                ans += abs(num);
            }
        }
        return negCnt % 2 == 0 ? ans : ans - minAbs * 2;
    }
};
