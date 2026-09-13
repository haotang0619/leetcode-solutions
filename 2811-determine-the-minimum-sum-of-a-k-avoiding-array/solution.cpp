class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        unordered_set<int> st;
        for(int i = 0, num = 1; i < n; i++) {
            while(st.contains(k - num)) num++;
            st.insert(num), ans += num++;
        }
        return ans;
    }
};
