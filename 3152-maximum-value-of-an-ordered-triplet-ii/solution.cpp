class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        stack<int> st;
        st.push(nums.back());
        for(int i = nums.size() - 2; i >= 2; i--) {
            st.push(max(st.top(), nums[i]));
        }
        int max_now = nums[0];
        long long ans = 0;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(i >= 2) st.pop();
            if(max_now > nums[i]) {
                ans = max(ans, (max_now - nums[i]) * (long long)st.top());
            } else max_now = nums[i];
        }
        return ans;
    }
};
