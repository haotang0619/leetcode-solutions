class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n, 0);
        for(int i = 0; i < n; i++) indices[i] = i;
        sort(indices.begin(), indices.end(), [&](auto a, auto b) {
            return positions[a] < positions[b];
        });
        stack<pair<int, int>> st;
        for(auto i : indices) {
            if(directions[i] == 'R') st.push({i, healths[i]});
            else {
                while(!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    int j = top.first, h = top.second;
                    if(h > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                        st.push({j, healths[j]});
                        break;
                    } else if(h == healths[i]) {
                        healths[i] = healths[j] = 0;
                        break;
                    } else {
                        healths[j] = 0;
                        healths[i]--;
                    }
                }
            }
        }
        vector<int> ans;
        for(auto x : healths) {
            if(x > 0) ans.push_back(x);
        }
        return ans;
    }
};
