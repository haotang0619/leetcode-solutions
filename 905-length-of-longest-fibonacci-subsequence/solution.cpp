class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> mp;
        unordered_map<int, int> idx;
        int ans = 0, n = arr.size();
        mp.resize(n, vector<int>(n, 0));
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[i][j] = 2;
            }
        }
        for(int i = 0; i < n; i++) idx[arr[i]] = i;
        for(int i = 2; i < n; i++) {
            for(int j = 0; j < i - 1; j++) {
                int diff = arr[i] - arr[j];
                if(idx.find(diff) != idx.end()) {
                    if(mp[j][idx[diff]] > 0) {
                        int result = max(mp[idx[diff]][i], mp[j][idx[diff]] + 1);
                        mp[idx[diff]][i] = result;
                        ans = max(ans, result);
                    }
                }
            }
        }
        return ans;
    }
};
