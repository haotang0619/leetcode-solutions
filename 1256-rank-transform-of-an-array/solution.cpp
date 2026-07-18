class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int& a, int& b) {
            return arr[a] < arr[b];
        });
        vector<int> ans(n);
        int prev = INT_MIN, idx = 0;
        for(auto& i : indices) {
            if(arr[i] == prev) ans[i] = idx;
            else ans[i] = ++idx;
            prev = arr[i];
        }
        return ans;
    }
};
