class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> mp;
        for(auto x : items) {
            mp[x[0]] = max(mp[x[0]], x[1]);
        }
        
        int max_now = INT_MIN;
        vector<pair<int, int>> v;
        for(auto &m : mp) {
            max_now = max(max_now, m.second);
            v.push_back({m.first, max_now});
        }

        vector<int> ans;
        for(auto x : queries) {
            if(x < v[0].first) {
                ans.push_back(0);
                continue;
            }

            int left = 0, right = v.size() - 1;
            while(left < right) {
                int mid = (left + right) / 2;
                if (v[mid].first <= x && v[mid + 1].first > x) {
                    left = mid;
                    break;
                } else if (v[mid].first <= x) left = mid + 1;
                else right = mid;
            }
            ans.push_back(v[left].second);
        }
        return ans;
    }
};
