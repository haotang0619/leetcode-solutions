class Solution {
public:
    int mod = 1e9 + 7;
    int rectangleArea(vector<vector<int>>& rectangles) {
        rectangles.push_back({INT_MAX, INT_MAX, INT_MAX, INT_MAX});
        sort(rectangles.begin(), rectangles.end(), [&](auto& a, auto& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[2] < b[2];
        });
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<>> pq; // [x2, i]
        unordered_set<int> st;

        auto getArea = [&](int l, int r) {
            vector<pii> v;
            for(auto& i : st) {
                auto& r = rectangles[i];
                v.push_back({r[1], r[3]});
            }
            sort(v.begin(), v.end());
            long long h = 0;
            pii curr = {-1, -1};
            v.push_back({INT_MAX, INT_MAX});
            for(auto& [y1, y2] : v) {
                if(curr.second >= y1) curr.second = max(curr.second, y2);
                else h += curr.second - curr.first, curr = {y1, y2};
            }
            return h * (r - l) % mod;
        };

        long long ans = 0;
        int n = rectangles.size(), prev = -1;
        for(int i = 0; i < n; i++) {
            auto& r = rectangles[i];
            int x1 = r[0], x2 = r[2];
            while(!pq.empty() && pq.top().first <= x1) {
                auto [r, idx] = pq.top();
                ans = (ans + getArea(prev, r)) % mod;
                prev = r;
                pq.pop(), st.erase(idx);
            }
            ans = (ans + getArea(prev, x1)) % mod;
            prev = x1;
            pq.push({x2, i}), st.insert(i);
        }
        return ans;
    }
};
