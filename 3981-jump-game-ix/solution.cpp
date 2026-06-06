class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> e(n, vector<int>({}));
        int maxIdx = 0, maxVal = nums[0];
        // Edge to left max element
        for(int i = 1; i < n; i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            } else e[i].push_back(maxIdx);
        }
        // Edge to rightmost smaller element
        vector<int> minFromEnd(n, nums[n - 1]);
        for(int i = n - 2; i >= 0; i--) {
            minFromEnd[i] = min(minFromEnd[i + 1], nums[i]);
        }
        for(int i = 0; i < n; i++) {
            auto beg = minFromEnd.begin() + i + 1, end = minFromEnd.end();
            int idx = lower_bound(beg, end, nums[i]) - beg + i;
            if(idx > i) e[i].push_back(idx);
        }
        // DFS
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(ans[i] != -1) continue;
            stack<int> st;
            set<int> visit;
            st.push(i);
            while(!st.empty()) {
                int top = st.top();
                ans[i] = max(ans[i], nums[top]);
                st.pop();
                for(auto x : e[top]) {
                    if(ans[x] != -1) ans[i] = max(ans[i], ans[x]);
                    else if(!visit.contains(x)) {
                        visit.insert(x);
                        st.push(x);
                    }
                }
            }
            for(auto x : visit) ans[x] = ans[i];
        }
        return ans;
    }
};
