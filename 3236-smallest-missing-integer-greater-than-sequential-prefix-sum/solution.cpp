class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int> st;
        st.insert(nums[0]);
        bool flag = true;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[0] + i) flag = false;
            else if(flag) sum += nums[i];
            st.insert(nums[i]);
        }
        while(st.contains(sum)) sum++;
        return sum;
    }
};
