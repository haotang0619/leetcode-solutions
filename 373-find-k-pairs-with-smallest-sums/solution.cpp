class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        vector<vector<int>> ans;
        set<vector<int>> st;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        st.insert({0, 0});
        
        while(ans.size() < k) {
            auto top = pq.top().second;
            int i = top[0], j = top[1];
            ans.push_back({nums1[i], nums2[j]});
            pq.pop();
            if(j + 1 < nums2.size() && !st.contains({i, j + 1})) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
            if(i + 1 < nums1.size() && !st.contains({i + 1, j})) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
        }
        return ans;
    }
};
