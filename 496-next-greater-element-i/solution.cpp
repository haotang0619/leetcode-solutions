class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> sk;
        for(int i = 0; i < nums2.size(); i++) {
            while(!sk.empty() && sk.top() < nums2[i]) {
                int top = sk.top();
                sk.pop();
                mp[top] = nums2[i];
            }
            sk.push(nums2[i]);
        }
        vector<int> ans;
        for(auto x : nums1) ans.push_back(mp.contains(x) ? mp[x] : -1);
        return ans;
    }
};
