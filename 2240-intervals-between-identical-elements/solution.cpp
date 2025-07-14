class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i]) == mp.end()) mp[arr[i]] = {};
            mp[arr[i]].push_back(i);
        }
        vector<long long> ans(arr.size(), 0);
        for(auto [num, v] : mp) {
            int n = v.size();
            vector<long long> pSum(n, v[0]);
            for(int j = 1; j < n; j++) pSum[j] = pSum[j - 1] + v[j];
            for(int j = 0; j < n; j++) {
                long long i = v[j];
                if(j > 0) ans[i] += i * j - pSum[j - 1];
                if(j < n - 1) ans[i] += (pSum[n - 1] - pSum[j]) - (i * (n - 1 - j));
            }
        }
        return ans;
    }
};
