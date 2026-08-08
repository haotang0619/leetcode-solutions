class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<long long>> mxHere(n + 1, vector<long long>(m + 1, 0));
        long long ans = LLONG_MIN;
        for(int k = 1; k <= K; k++) {
            vector<vector<long long>> newMxHere(n + 1, vector<long long>(m + 1, LLONG_MIN));
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    long long mxPrev = mxHere[i - 1][j - 1];
                    if(mxPrev == LLONG_MIN) continue;
                    newMxHere[i][j] = max(
                        newMxHere[i][j], 
                        mxPrev + (long long)nums1[i - 1] * nums2[j - 1]
                    );
                    newMxHere[i][j] = max(newMxHere[i][j], newMxHere[i - 1][j]);
                    newMxHere[i][j] = max(newMxHere[i][j], newMxHere[i][j - 1]);
                    if(k == K) ans = max(ans, newMxHere[i][j]);
                }
            }
            mxHere = newMxHere;
        }
        return ans;
    }
};
