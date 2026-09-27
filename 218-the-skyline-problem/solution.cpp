class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> st;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<vector<int>> ans;
        buildings.push_back({-1, -1, -1});
        for(auto& x : buildings) {
            bool flag = false;
            long long l = x[0], r = x[1], h = x[2];
            if(l == -1) l = INT_MAX + 1LL;
            while(!pq.empty() && pq.top().first <= l) {
                auto [r1, h1] = pq.top();
                pq.pop();
                bool isHighest = (*prev(st.end()) == h1);
                st.erase(st.find(h1));
                if(isHighest) {
                    if(st.empty()) {
                        if(r1 < l) ans.push_back({r1, 0});
                    } else {
                        int h2 = *prev(st.end());
                        if(r1 < l && h2 < h1 || r1 == l && h2 > h) {
                            ans.push_back({r1, *prev(st.end())});
                        }
                    }
                }
            }
            if(l > INT_MAX) break;

            st.insert(h);
            pq.push({r, h});
            if(h == *prev(st.end())) {
                while(!ans.empty() && ans.back()[0] == l) ans.pop_back();
                int prevH = ans.size() == 0 ? -1 : ans.back()[1];
                if(prevH != h) ans.push_back({(int)l, (int)h});
            }
        }
        return ans;
    }
};
