// Had the correct idea but checked the hints to make sure
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        unordered_set<int> st;
        st.insert(0);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            unordered_set<int> tmp;
            for(auto &num : st) {
                int val1 = num + stones[i], val2 = num - stones[i];
                tmp.insert(val1);
                tmp.insert(val2);
                if(i == n - 1 && val1 >= 0) ans = min(ans, val1);
                if(i == n - 1 && val2 >= 0) ans = min(ans, val2);
            }
            st = tmp;
        }
        return ans;
    }
};
