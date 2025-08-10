class Solution {
public:
    // Saw solution
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pSum(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            int rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += matrix[i][j];
                pSum[i][j] = rowSum;
            }
        }

        int ans = 0;
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = j1; j2 < n; j2++) {
                map<int, int> mp;
                int sum = 0;
                for(int i = 0; i < m; i++) {
                    sum += pSum[i][j2] - (j1 > 0 ? pSum[i][j1 - 1] : 0);
                    if(sum == target) ans++;
                    int left = sum - target;
                    if(mp.find(left) != mp.end()) ans += mp[left];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};
