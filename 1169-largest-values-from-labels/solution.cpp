class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v;
        for(int i = 0; i < values.size(); i++) v.push_back({values[i], labels[i]});
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        unordered_map<int, int> mp;
        int ans = 0, cnt = 0;
        for(auto [val, lab] : v) {
            if(cnt >= numWanted) break;
            if(mp[lab] < useLimit) {
                ans += val;
                mp[lab]++;
                cnt++;
            }
        }
        return ans;
    }
};
