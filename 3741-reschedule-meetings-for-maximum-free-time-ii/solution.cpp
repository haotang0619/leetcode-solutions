class Solution {
public:
    int bsearch(vector<pair<int, int>>& v, int target) {
        int l = 0, r = v.size() - 1, pos = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(v[m].first >= target) {
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        return pos;
    }

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> spaces;
        map<int, int> spaceCnts;
        int n = startTime.size(), prev = 0;
        for(int i = 0; i <= n; i++) {
            int start = i == n ? eventTime : startTime[i];
            int space = start - prev;
            spaces.push_back(space);
            spaceCnts[space]++;
            if(i < n) prev = endTime[i];
        }
        
        int size = spaceCnts.size();
        vector<pair<int, int>> v(size, pair<int, int>{0, 0});
        int pos = size - 1;
        for(auto [len, cnt] : spaceCnts) v[pos--] = {len, cnt};
        for(int i = 1; i < size; i++) v[i].second += v[i - 1].second;
                
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, spaces[i] + spaces[i + 1]);
            int len = endTime[i] - startTime[i], toSub = 0;
            if(spaces[i] >= len) toSub++;
            if(spaces[i + 1] >= len) toSub++;

            int pos = bsearch(v, len);
            if(pos >= 0 && v[pos].second - toSub > 0) {
                ans = max(ans, spaces[i] + spaces[i + 1] + len);
            }
        }
        return ans;
    }
};
