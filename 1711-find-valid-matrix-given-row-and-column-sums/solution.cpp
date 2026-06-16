class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = colSum.size(), n = rowSum.size();
        vector<int> colIndices(m), rowIndices(n);
        iota(colIndices.begin(), colIndices.end(), 0);
        iota(rowIndices.begin(), rowIndices.end(), 0);
        sort(colIndices.begin(), colIndices.end(), [&](int &a, int &b) {
            return colSum[a] > colSum[b];
        });
        sort(rowIndices.begin(), rowIndices.end(), [&](int &a, int &b) {
            return rowSum[a] < rowSum[b];
        });
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(auto &r : rowIndices) {
            int rSum = rowSum[r];
            while(rSum > 0) {
                int leftCol = 0, minColSum = INT_MAX;
                for(auto &x : colSum) {
                    if(x > 0) {
                        leftCol++;
                        minColSum = min(minColSum, x);
                    }
                }
            
                int round = min(rSum / leftCol, minColSum);
                int nextRSum;
                if(round >= 1) {
                    nextRSum = rSum - round * leftCol;
                    for(int i = 0; i < m; i++) {
                        int c = colIndices[i];
                        if(colSum[c] == 0) continue;
                        ans[r][c] += round;
                        colSum[c] -= round;
                    }
                } else {
                    nextRSum = 0;
                    for(int i = 0, j = 0; i < rSum; i++, j++) {
                        while(colSum[colIndices[j % m]] <= 0) j++;
                        int c = colIndices[j % m];
                        ans[r][c] += 1;
                        colSum[c] -= 1;
                    }
                }
                rSum = nextRSum;
            }
        }
        return ans;
    }
};

