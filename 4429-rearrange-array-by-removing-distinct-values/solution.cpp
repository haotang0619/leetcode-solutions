class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans, nums1 = nums;
        while(nums1.size() > 0) {
            set<int> st;
            vector<int> nums2;
            for(auto& num : nums1) {
                if(st.contains(num)) nums2.push_back(num);
                else st.insert(num);
            }
            nums1 = nums2;
            ans.insert(ans.end(), st.begin(), st.end());
        }
        return ans;
    }
};
