class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long> mp;
        for(auto x : arr) mp[x] = 1;
        long long ans = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            long long now = 1;
            for(int j = 0; arr[j] <= sqrt(arr[i]); j++) {
                if(arr[i] % arr[j] == 0) {
                    int k = arr[i] / arr[j];
                    now = (now + mp[arr[j]] * mp[k] * (arr[j] == k ? 1 : 2)) % mod;
                }
            }
            mp[arr[i]] = now;
            ans = (ans + now) % mod;
        }
        return ans;
    }
};
