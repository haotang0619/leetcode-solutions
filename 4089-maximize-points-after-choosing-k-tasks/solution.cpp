class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](auto& a, auto& b) {
            int diff1 = technique1[a] - technique2[a];
            int diff2 = technique1[b] - technique2[b];
            return diff1 > diff2;
        });
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int idx = indices[i];
            if(i < k || technique1[idx] >= technique2[idx]) ans += technique1[idx];
            else ans += technique2[idx];
        }
        return ans;
    }
};
