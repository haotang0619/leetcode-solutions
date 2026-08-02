class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> mp1, mp2;
        int n = planks.size();
        for(int i = 0; i < n; i++) mp1[planks[i]]++;
        vector<pair<int, int>> v(mp1.begin(), mp1.end());
        for(int i = 0; i < v.size(); i++) {
            for(int j = i; j < v.size(); j++) {
                if(i == j) {
                    auto& [h, cnt] = v[i];
                    mp2[h * 2] += cnt / 2;
                } else {
                    auto& [h1, cnt1] = v[i];
                    auto& [h2, cnt2] = v[j];
                    mp2[h1 + h2] += min(cnt1, cnt2);
                }
            }
        }
        unordered_map<int, int> mp3;
        for(auto& [h, cnt] : mp1) mp3[h] += cnt;
        for(auto& [h, cnt] : mp2) mp3[h] += cnt;
        int ans = 1;
        for(auto& [h, cnt] : mp3) ans = max(ans, cnt);
        return ans;
    }
};
