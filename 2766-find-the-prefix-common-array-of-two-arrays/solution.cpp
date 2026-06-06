class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> v(n + 1, 0);
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            v[A[i]] |= 1;
            v[B[i]] |= 2;
            for(auto x : v) ans[i] += x == 3 ? 1 : 0; 
        }
        return ans;
    }
};
