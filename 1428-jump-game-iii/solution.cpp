class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> e(n, vector<int>({}));
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) continue;
            if(i - arr[i] >= 0) e[i].push_back(i - arr[i]);
            if(i + arr[i] < n) e[i].push_back(i + arr[i]);
        }
        vector<bool> visit(n, false);
        visit[start] = true;
        stack<int> st;
        st.push(start);
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(arr[top] == 0) return true;
            else {
                for(auto x : e[top]) {
                    if(!visit[x]) {
                        visit[x] = true;
                        st.push(x);
                    }
                }
            }
        }
        return false;
    }
};
