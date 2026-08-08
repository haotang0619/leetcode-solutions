class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<int, long long>, int> mp; // [num, sum] => cnt
        int n = capacity.size();
        long long ans = 0, sum1 = 0, sum2 = capacity[0] + capacity[1];
        for(int i = 0, j = 2; j < n; i++, j++) {
            sum1 += capacity[i];
            mp[{capacity[i], sum1}]++;
            long long target = sum2 - capacity[j];
            ans += mp[{capacity[j], target}];
            sum2 += capacity[j];
        }
        return ans;
    }
};
